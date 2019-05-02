/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-04-18
 *
 * IRQ initialization functions
 ***************************************************************************/

#include "ps2.h"
#include "isr.h"
#include "segment.h"

extern int printk(const char *fmt, ...) __attribute__ ((format (printf, 1, 2)));

void c_intr_handler(int irq, int errorCode) {
   if (irq_table[irq].handler)
      (*irq_table[irq].handler)(0, 0, irq_table[irq].arg);
   else
      printk("No handler for this interrupt! - IRQ%d", irq);
   IRQ_EOI(irq);
}

void keyboard_interrupt() {
   char ch;
   if ((ch = get_ascii()))
      printk("%c", ch);
}


void IRQ_set_handler(int irq, irq_handler_t handler, void *arg) {
   irq_table[irq].handler = handler;
   irq_table[irq].arg = arg;
}

void IRQ_EOI(int irq) {
   if (irq >= 8)
      outb(PIC_EOI, PIC2_COMMAND);

   outb(PIC_EOI, PIC1_COMMAND);
}

void IRQ_init(void) {
   int i/*, loop = 0*/;
   CLI();
   PIC_remap(0x20, 0x28);
   /*(*isr_table[0])();*/

   for (i=0; i < NUM_IRQS; i++) {
      if (i != 1)
         IRQ_set_mask(i);
      idt_table[i].offset1 =  (uintptr_t) isr_table[i]        & 0xFFFF;
      idt_table[i].offset2 = ((uintptr_t) isr_table[i] >> 16) & 0xFFFF;
      idt_table[i].offset3 = ((uintptr_t) isr_table[i] >> 32) & 0xFFFFFFFF;
      idt_table[i].dpl = 0;
      idt_table[i].ist = 0;
      idt_table[i].selector = 8;
      idt_table[i].present = 1;
      idt_table[i].zero = 0;
      idt_table[i].type = 0xE;
      IRQ_set_handler(i, 0, 0);
   }
   lidt(idt_table, NUM_IRQS*sizeof(idt_entry));
   IRQ_set_handler(33, keyboard_interrupt, (void *) PS2_DATA_PORT);
   
   tss_table.ist1 = (uint64_t) df_stack + STACK_SIZE - 1;
   tss_table.ist2 = (uint64_t) pf_stack + STACK_SIZE - 1;
   tss_table.ist3 = (uint64_t) gp_stack + STACK_SIZE - 1;
   idt_table[8].ist = 1;
   idt_table[14].ist = 2;
   idt_table[13].ist = 3;

   ltr(0x20);

   /*while (!loop);*/
   STI();
}

void PIC_remap(int offset1, int offset2) {
   unsigned char a1, a2;

   a1 = inb(PIC1_DATA);
   a2 = inb(PIC2_DATA);

   outb(ICW1_INIT | ICW1_ICW4, PIC1_COMMAND);
   io_wait();
   outb(ICW1_INIT | ICW1_ICW4, PIC2_COMMAND);
   io_wait();
   outb(offset1, PIC1_DATA);
   io_wait();
   outb(offset2, PIC2_DATA);
   io_wait();
   outb(4, PIC1_DATA);
   io_wait();
   outb(2, PIC2_DATA);
   io_wait();

   outb(ICW4_8086, PIC1_DATA);
   io_wait();
   outb(ICW4_8086, PIC2_DATA);
   io_wait();

   outb(a1, PIC1_DATA);
   outb(a2, PIC2_DATA);
}

void IRQ_set_mask(unsigned char IRQline) {
   uint16_t port;
   uint8_t value;

   if (IRQline < 8)
      port = PIC1_DATA;
   else {
      port = PIC2_DATA;
      IRQline -= 8;
   }
   value = inb(port) | (1 << IRQline);
   outb(value, port);
}

void IRQ_clear_mask(unsigned char IRQline) {
    uint16_t port;
    uint8_t value;
 
    if(IRQline < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        IRQline -= 8;
    }
    value = inb(port) & ~(1 << IRQline);
    outb(value, port);        
}

int IRQ_get_mask(int IRQline) {
   uint16_t port;

   if (IRQline < 8)
      port = PIC1_DATA;
   else {
      port = PIC2_DATA;
      IRQline -= 8;
   }
   return inb(port);
}

/* Helper func */
static uint16_t __pic_get_irq_reg(int ocw3) {
    /* OCW3 to PIC CMD to get the register values.  PIC2 is chained, and
     * represents IRQs 8-15.  PIC1 is IRQs 0-7, with 2 being the chain */
    outb(ocw3, PIC1_COMMAND);
    outb(ocw3, PIC2_COMMAND);
    return (inb(PIC2_COMMAND) << 8) | inb(PIC1_COMMAND);
}

/* Returns the combined value of the cascaded PICs irq request register */
uint16_t pic_get_irr(void) {
    return __pic_get_irq_reg(PIC_READ_IRR);
}

/* Returns the combined value of the cascaded PICs in-service register */
uint16_t pic_get_isr(void) {
    return __pic_get_irq_reg(PIC_READ_ISR);
}


/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-04-18
 *
 * IRQ initialization functions
 ***************************************************************************/

#ifndef INTERRUPT_H
#define INTERRUPT_H

   #include <stdint-gcc.h>

   #define PIC1            0x20
   #define PIC2            0xA0
   #define PIC1_COMMAND    PIC1
   #define PIC1_DATA       (PIC1+1)
   #define PIC2_COMMAND    PIC2
   #define PIC2_DATA       (PIC2+1)

   #define PIC_EOI         0x20

   #define ICW1_ICW4       0x01
   #define ICW1_SINGLE     0x02
   #define ICW1_INTERVAL4  0X04
   #define ICW1_LEVEL      0x08
   #define ICW1_INIT       0x10

   #define ICW4_8086       0x01
   #define ICW4_AUTO       0x02
   #define ICW4_BUF_SLAVE  0x08
   #define ICW4_BUF_MASTER 0x0C
   #define ICW4_SFNM       0x10

   #define PIC_READ_IRR    0x0A    /* OCW3 irq ready next CMD read */
   #define PIC_READ_ISR    0x0B    /* OCW3 irq service next CMD read */

   #define NUM_IRQS        256

   #define STACK_SIZE      4096

   typedef void (*irq_handler_t)(int, int, void*);

   static struct {
      void *arg;
      irq_handler_t handler;
   } irq_table[NUM_IRQS];

   typedef struct __attribute__ ((__packed__)) idt_struct {
      uint16_t offset1;
      uint16_t selector;

      uint8_t  ist:3;
      uint8_t  ign1:5;
      uint8_t  type:4;
      uint8_t  zero:1;
      uint8_t  dpl:2;
      uint8_t  present:1;

      uint16_t offset2;
      uint32_t offset3;
      uint32_t ign2;
   } idt_entry;
   idt_entry idt_table[NUM_IRQS];


   uint8_t df_stack[STACK_SIZE];
   uint8_t pf_stack[STACK_SIZE];
   uint8_t gp_stack[STACK_SIZE];

   void IRQ_set_handler(int irq, irq_handler_t handler, void *arg);
   void IRQ_EOI(int irq);
   void IRQ_init(void);
   void PIC_remap(int offset1, int offset2);
   void IRQ_set_mask(unsigned char IRQline);
   void IRQ_clear_mask(unsigned char IRQline);
   int IRQ_get_mask(int IRQline);
   uint16_t pic_get_irr(void);
   uint16_t pic_get_isr(void);

#endif

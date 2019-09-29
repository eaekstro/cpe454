/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-04-09
 *
 * kernel main function
 ***************************************************************************/

#include "assem.h"
#include "vga_display.h"
#include "ps2.h"
#include "interrupt.h"
#include "segment.h"
#include "serial.h"
#include "memman.h"

int kernel_main(unsigned long addr) {
   int loop = 0;
   
   segment_init();
   ps2_init();
   keyboard_init();
   IRQ_init();
   SER_init();
   parse_multiboot(addr);

   /*while(9) {
      if ((ch = get_ascii()))
         printk("%c", ch);
   }
   printk("asdfasdfasdfasdfas\n");
   printk("blah blah blah\n");
   allocate_all_pages();*/
   while (!loop);

   return 1;
}

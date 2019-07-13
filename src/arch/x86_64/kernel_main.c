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

int kernel_main() {
   int loop = 0;
   
   segment_init();
   ps2_init();
   keyboard_init();
   
   IRQ_init();
   SER_init();

   /*while(9) {
      if ((ch = get_ascii()))
         printk("%c", ch);
   }*/
   SER_write("asdfasdfasdfasdfas", 18);
   while (!loop);

   return 1;
}

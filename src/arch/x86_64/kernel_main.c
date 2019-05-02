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

int kernel_main() {
   int loop = 0;
   
   segment_init();
   ps2_init();
   keyboard_init();
   
   IRQ_init();

   /*while(9) {
      if ((ch = get_ascii()))
         printk("%c", ch);
   }*/
   while (!loop);

   return 1;
}

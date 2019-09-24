/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-09-09
 *
 * Memory manager functions
 ***************************************************************************/

#include "memman.h"

extern int printk(const char *fmt, ...) __attribute__ ((format (printf, 1, 2)));

void parse_multiboot(unsigned long addr) {
   multiboot_tag *tag;
   /*if (magic != MULTIBOOT_MAGIC) {
      printk("invalid magic: %lx\n", magic);
      return;
   }*/
   printk("Tag starting at addr %lx\n", addr);

   for (tag = (multiboot_tag *) (addr + 8); tag->type != 0 && tag->size != 8;
        tag = (multiboot_tag *) ((uint8_t *) tag + ((tag->size + 7) & ~7))) {
      printk("TAG TYPE: %d\n",  tag->type);
      if (tag->type == 2)
         printk("BOOTLOADER: %s\n", (uint8_t *) tag + 8);
   }
}


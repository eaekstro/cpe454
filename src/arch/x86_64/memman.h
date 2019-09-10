/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-09-09
 *
 * Memory manager functions
 ***************************************************************************/

#ifndef MEMMAN_H
#define MEMMAN_H

   #include <stdint-gcc.h>

   #define MULTIBOOT_MAGIC 0x36d76289

   typedef struct mult_tag {
      uint32_t type;
      uint32_t size;
   } multiboot_tag;

   void parse_multiboot(unsigned long magic, unsigned long addr);

#endif

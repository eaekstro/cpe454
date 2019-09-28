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

   #define MULTIBOOT_TYPE_END       0
   #define MULTIBOOT_TYPE_BOOTCMD   1
   #define MULTIBOOT_TYPE_BOOTNAME  2
   #define MULTIBOOT_TYPE_BASICMEM  4
   #define MULTIBOOT_TYPE_BIOSDEV   5
   #define MULTIBOOT_TYPE_MMAP      6
   #define MULTIBOOT_TYPE_ELF       9

   typedef struct __attribute__ ((__packed__)) mult_tag {
      uint32_t type;
      uint32_t size;
   } multiboot_tag;

   typedef struct __attribute__ ((__packed__)) mult_string {
      uint32_t type;
      uint32_t size;
      char str[0];
   } multiboot_string;

   typedef struct __attribute__ ((__packed__)) mult_tag_mmap {
      uint32_t type;
      uint32_t size;
      uint32_t entry_size;
      uint32_t entry_version;
      uint8_t  entries[0];
   } multiboot_tag_mmap;
   
   typedef struct __attribute__ ((__packed__)) mult_mmap {
      uint64_t addr;
      uint64_t len;
      uint32_t type;
      uint32_t zero;
   } multiboot_mmap;

   typedef struct __attribute__ ((__packed__)) mult_tag_elf {
      uint32_t type;
      uint32_t size;
      uint32_t num_entries;
      uint32_t entry_size;
      uint32_t string_table_idx;
      uint8_t  entries[0];
   } multiboot_tag_elf;

   typedef struct __attribute__ ((__packed__)) mult_elf {
      uint32_t name_idx;
      uint32_t type;
      uint64_t flags;
      uint64_t seg_addr;
      uint64_t seg_offset;
      uint64_t seg_size;
      uint32_t idx_link;
      uint32_t extra_info;
      uint64_t addr_align;
      uint64_t iff_section;
   } multiboot_elf;

   void parse_multiboot(unsigned long addr);

#endif

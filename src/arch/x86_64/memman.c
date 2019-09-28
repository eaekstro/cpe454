/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-09-09
 *
 * Memory manager functions
 ***************************************************************************/

#include "memman.h"

extern int printk(const char *fmt, ...) __attribute__ ((format (printf, 1, 2)));
static void load_mmap(multiboot_tag *tag);
static void load_elf(multiboot_tag *tag);

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
      switch (tag->type) {
         case MULTIBOOT_TYPE_BOOTCMD:
            printk("BOOTLOADER CMD:::  %s\n\n", ((multiboot_string *) tag)->str);
            break;
         case MULTIBOOT_TYPE_BOOTNAME:
            printk("BOOTLOADER NAME::: %s\n\n", ((multiboot_string *) tag)->str);
            break;
         case MULTIBOOT_TYPE_MMAP:
            printk("MMAP:::\n");
            load_mmap(tag);
            break;
         case MULTIBOOT_TYPE_ELF:
            printk("ELF:::\n");
            load_elf(tag);
            break;
      }
   }
}

static void load_mmap(multiboot_tag *tag) {
   multiboot_mmap *entry;
   int entry_idx = 1;
   for (entry = (multiboot_mmap *) ((multiboot_tag_mmap *) tag)->entries;
        ((uint64_t) entry - (uint64_t) tag) < tag->size;
        entry = (multiboot_mmap *) ((uint64_t) entry 
           + ((multiboot_tag_mmap *) tag)->entry_size)) {
      printk("   ENTRY %d\n", entry_idx); 
      printk("   ADDRESS: %lx\n" , entry->addr);
      printk("   LENGTH:  %lx\n" , entry->len );
      printk("   TYPE:    %x\n\n", entry->type);
      entry_idx++;
   }
}

static void load_elf(multiboot_tag *tag) {
   multiboot_tag_elf *etag = (multiboot_tag_elf *) tag;
   multiboot_elf *entry, *init_entry = etag->entries;
   int entry_idx = 1;
   for (entry = (multiboot_elf *)  etag->entries;
        entry_idx <=  etag->num_entries;
        entry = (multiboot_elf *) ((uint64_t) entry + etag->entry_size)) {
      printk("   ENTRY %d\n", entry_idx); 
      printk("   NAME:  %s\n",  
         &((char *) init_entry[etag->string_table_idx].seg_addr)[entry->name_idx] );
      printk("   TYPE:  %x\n",  entry->type );
      printk("   FLAGS: %lx\n", entry->flags);
      printk("   SEG ADDRESS: %lx\n",   entry->seg_addr);
      printk("   SEG OFFSET:  %lx\n",   entry->seg_offset);
      printk("   SEG SIZE:    %lx\n\n", entry->seg_size);
      entry_idx++;
   }
}

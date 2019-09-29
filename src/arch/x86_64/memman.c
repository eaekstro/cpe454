/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-09-09
 *
 * Memory manager functions
 ***************************************************************************/

#include "memman.h"

extern int printk(const char *fmt, ...) __attribute__ ((format (printf, 1, 2)));
static void load_mmap(multiboot_tag *tag, multiboot_tag *elf);
static void load_elf(multiboot_tag *tag);
static void free_mmap_pages(multiboot_mmap *entry, multiboot_tag_elf *elf);
static uint8_t contains_elf_section(uint64_t start, multiboot_tag_elf *etag);
static void remove_elf_pages(multiboot_elf *entry);

static page_node *head = NULL;
static page_node *tail = NULL;

static long int num_pages = 0;

void allocate_all_pages(void) {
   uint8_t *page;
   while ((page = MMU_pf_alloc()) != NULL)
      printk("-- %lx allocated --\n", page);

   printk("\n::::: ALL PAGES ALLOCATED :::::\n");
}

void *MMU_pf_alloc(void) {
   page_node *temp;
   if (!head)
      return NULL;

   if (head == tail)
      tail = NULL;

   temp = head;
   head = head->next;
   head->prev = NULL;

   return (void *) ((uint64_t) temp + sizeof(page_node));
}

void MMU_pf_free(void *pf) {
   if (!head) {
      head = (page_node *) pf;
      head->next = NULL;
      head->prev = NULL;
      tail = head;
   }
   else {
      tail->next = (page_node *) pf;
      tail->next->prev = tail;
      tail = tail->next;
      tail->next = NULL;
   }
}

void parse_multiboot(unsigned long addr) {
   multiboot_tag *tag, *init_tag, *mmap, *elf;
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
            mmap = tag;
            break;
         case MULTIBOOT_TYPE_ELF:
            printk("ELF:::\n");
            elf = tag;
            break;
      }
   }
   load_mmap(mmap, elf);
   /*load_elf(tag);*/
}

static void load_mmap(multiboot_tag *tag, multiboot_tag *elf) {
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
      if (entry->type == 1)
         free_mmap_pages(entry, (multiboot_tag_elf *) elf);
      entry_idx++;
   }
   printk("===> %ld pages freed\n\n", num_pages);
}

/* Not currently used */
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
      if (entry->seg_addr > 0)
         remove_elf_pages(entry);
      entry_idx++;
   }
}

static void free_mmap_pages(multiboot_mmap *entry, multiboot_tag_elf *elf) {
   uint64_t start;
   int64_t  length = entry->len - 4096;
   for (start = entry->addr; length > 0; start += 4096) {
      if (!contains_elf_section(start, elf)) {
         MMU_pf_free((void *) start);
         num_pages++;
      }
      length -= 4096;
   }
}

static uint8_t contains_elf_section(uint64_t start, multiboot_tag_elf *etag) {
   multiboot_elf *entry;
   int entry_idx = 1;
   for (entry = (multiboot_elf *)  etag->entries;
        entry_idx <=  etag->num_entries;
        entry = (multiboot_elf *) ((uint64_t) entry + etag->entry_size)) {
      if (entry->seg_addr >= start && entry->seg_addr <= start + 4096) {
         printk("      Kernel Section - Page Removed::: %lx\n", start);
         return TRUE;
      }
      if (entry->seg_addr + entry->seg_size >= start 
         && entry->seg_addr + entry->seg_size <= start + 4096) {
         printk("      Kernel Section - Page Removed::: %lx\n", start);
         return TRUE;
      }
      if (entry->seg_addr <= start && entry->seg_addr + entry->seg_size >= start + 4096) {
         printk("      Kernel Section - Page Removed::: %lx\n", start);
         return TRUE;
      }
      entry_idx++;
   }

   return FALSE;
}


/* Not currently used */
static void remove_elf_pages(multiboot_elf *entry) {
   page_node *node = head;
   uint64_t start = entry->seg_addr, size = entry->seg_size;
   while ((uint64_t) node->next < start)
      node = node->next;

   while (size > 0 && node != NULL) {
      if ((uint64_t) node < start && (uint64_t) node->next > start) {
         if (node->prev)
            node->prev->next = node->next;
         if (node->next)
            node->next->prev = node->prev;
         node = node->next;
         size -= 4096;
         start += 4096;
      }
   }
}

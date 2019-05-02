/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-04-22
 *
 * Segmentation initialization
 ***************************************************************************/

#include "segment.h"

extern int printk(const char *fmt, ...) __attribute__ ((format (printf, 1, 2)));

void fill_code_entry(code_seg_desc *code_seg, uintptr_t base, uint32_t limit, uint8_t dpl) {
   code_seg->base_addr1 =  base        & 0xFFFF;
   code_seg->base_addr2 = (base >> 16) & 0xFF;
   code_seg->base_addr3 = (base >> 24) & 0xFF;
   /*code_seg->base_addr4 = (base >> 32) & 0xFFFFFFFF;*/
   
   code_seg->limit1 =  limit        & 0xFFFF;
   code_seg->limit2 = (limit >> 16) & 0xF;

   code_seg->one1 = 1;
   code_seg->one2 = 1;
   code_seg->dpl = dpl;
   code_seg->L = 1;
   
   code_seg->present = 1;
}

void fill_data_entry(data_seg_desc *data_seg, uintptr_t base, uint32_t limit, uint8_t dpl) {
   data_seg->base_addr1 =  base        & 0xFFFF;
   data_seg->base_addr2 = (base >> 16) & 0xFF;
   data_seg->base_addr3 = (base >> 24) & 0xFF;
   /*data_seg->base_addr4 = (base >> 32) & 0xFFFFFFFF;*/
   
   data_seg->limit1 =  limit        & 0xFFFF;
   data_seg->limit2 = (limit >> 16) & 0xF;

   data_seg->zero = 0;
   data_seg->one = 1;
   data_seg->dpl = dpl;

   data_seg->present = 1;
}

void fill_tss_entry(tss_desc *tss_entry, uintptr_t base, uint32_t limit, uint8_t dpl) {
   tss_entry->base_addr1 =  base        & 0xFFFF;
   tss_entry->base_addr2 = (base >> 16) & 0xFF;
   tss_entry->base_addr3 = (base >> 24) & 0xFF;
   tss_entry->base_addr4 = (base >> 32) & 0xFFFFFFFF;
   
   tss_entry->limit1 =  limit        & 0xFFFF;
   tss_entry->limit2 = (limit >> 16) & 0xF;

   tss_entry->type = 0x9;
   tss_entry->dpl = dpl;

   tss_entry->zero = 0;
   tss_entry->present = 1;
}

void segment_init() {
   fill_code_entry(  &(gdt_table.null_seg),                      0,                 0, 0);
   fill_code_entry(&(gdt_table.kernel_seg),       KERNEL_CODE_BASE,     SEGMENT_LIMIT, 0);
   fill_code_entry(  &(gdt_table.user_seg),         USER_CODE_BASE,     SEGMENT_LIMIT, 3);
   fill_data_entry( &(gdt_table.user_data),         USER_DATA_BASE,     SEGMENT_LIMIT, 3);
   fill_tss_entry(  &(gdt_table.tss_entry), (uintptr_t) &tss_table, sizeof(tss_table), 0);
   gdt_table.null_seg.one1 = 0;
   gdt_table.null_seg.one2 = 0;
   gdt_table.null_seg.present = 0;

   lgdt(&gdt_table, sizeof(gdt_table));
}


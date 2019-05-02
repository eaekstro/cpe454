/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-04-22
 *
 * Segmentation initialization
 ***************************************************************************/

#include "assem.h"

#define  KERNEL_CODE_BASE  0x000000
#define  USER_CODE_BASE    0x040000
#define  USER_DATA_BASE    0x080000

#define  SEGMENT_LIMIT     0x03ffff

typedef struct __attribute__ ((__packed__)) code_seg_struct {
   uint16_t limit1;
   uint16_t base_addr1;
   uint8_t  base_addr2;

   uint8_t  A:1;
   uint8_t  R:1;
   uint8_t  C:1;
   uint8_t  one1:1;
   uint8_t  one2:1;
   uint8_t  dpl:2;
   uint8_t  present:1;

   uint8_t  limit2:4;
   uint8_t  avl:1;
   uint8_t  L:1;
   uint8_t  D:1;
   uint8_t  G:1;

   uint8_t  base_addr3;
   /*uint32_t base_addr4;

   uint32_t ign:8;
   uint32_t pad2:5;
   uint32_t ign2:19;*/
} code_seg_desc;

typedef struct __attribute__ ((__packed__)) data_seg_struct {
   uint16_t limit1;
   uint16_t base_addr1;
   uint8_t  base_addr2;

   uint8_t  A:1;
   uint8_t  W:1;
   uint8_t  E:1;
   uint8_t  zero:1;
   uint8_t  one:1;
   uint8_t  dpl:2;
   uint8_t  present:1;

   uint8_t  limit2:4;
   uint8_t  avl:1;
   uint8_t  pad:1;
   uint8_t  DB:1;
   uint8_t  G:1;

   uint8_t  base_addr3;
   /*uint32_t base_addr4;

   uint32_t ign:8;
   uint32_t pad2:5;
   uint32_t ign2:19;*/
} data_seg_desc;

typedef struct __attribute__ ((__packed__)) tss_struct {
   uint16_t limit1;
   uint16_t base_addr1;
   uint8_t  base_addr2;

   uint8_t  type:4;
   uint8_t  zero:1;
   uint8_t  dpl:2;
   uint8_t  present:1;
   uint8_t  limit2:4;
   uint8_t  avl:1;
   uint8_t  pad:2;
   uint8_t  G:1;

   uint8_t  base_addr3;
   uint32_t base_addr4;

   uint32_t ign:8;
   uint32_t pad2:5;
   uint32_t ign2:19;
} tss_desc;

typedef struct __attribute__ ((__packed__)) tss_table_struct {
   uint32_t reserved1;
   uint64_t rsp0;
   uint64_t rsp1;
   uint64_t rsp2;
   uint64_t reserved2;
   uint64_t ist1;
   uint64_t ist2;
   uint64_t ist3;
   uint64_t ist4;
   uint64_t ist5;
   uint64_t ist6;
   uint64_t ist7;
   uint64_t reserved3;
   uint16_t reserved4;
   uint16_t io_map_base;
} tss_table_t;

typedef struct __attribute__ ((__packed__)) gdt_struct {
   code_seg_desc  null_seg;
   code_seg_desc  kernel_seg;
   code_seg_desc  user_seg;
   data_seg_desc  user_data;
   tss_desc       tss_entry;
} GDT;

uint64_t gdt_table2[4];

GDT            gdt_table;
tss_table_t    tss_table;

void segment_init();

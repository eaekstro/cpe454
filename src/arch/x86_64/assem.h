/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-04-15
 *
 * inline assembly functions
 ***************************************************************************/

#ifndef ASSEM_H
#define ASSEM_H
   
   #include <stdint-gcc.h>

   #define IF_FLAG   0x200

   void CLI(void);
   void STI(void);
   int interrupts_enabled(void);
   void ltr(uint8_t offset);
   void lidt(void *base, uint16_t size);
   void lgdt(void *base, uint16_t size);
   void outb(uint8_t val, uint16_t port);
   uint8_t inb(uint16_t port);
   void io_wait(void);

#endif

/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-04-15
 *
 * inline assembly functions
 ***************************************************************************/

#include "assem.h"

inline void CLI(void) {
   asm volatile ("cli");
}

inline void STI(void) {
   asm volatile ("sti");
}

inline int interrupts_enabled(void) {
   unsigned long flags;
   asm volatile ("# __raw_dave_flags\n\t"
                 "pushf ; pop %0"
                 : "=rm" (flags)
                 :
                 :"memory");
   return flags & IF_FLAG;
}
                  

inline void ltr(uint8_t offset) {
   asm ( "ltr %0" : : "m"(offset) );
}

inline void lidt(void *base, uint16_t size) {
   static struct {
      uint16_t length;
      void     *base;
   } __attribute__((packed)) IDTR;

   IDTR.length = size;
   IDTR.base = base;

   asm ( "lidt %0" : : "m"(IDTR) );
}

inline void lgdt(void *base, uint16_t size) {
   static struct {
      uint16_t length;
      void     *base;
   } __attribute__((packed)) GDTR;

   GDTR.length = size;
   GDTR.base = base;

   asm ( "lgdt %0" : : "m"(GDTR) );
}

inline void outb(uint8_t val, uint16_t port) {
   asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

inline uint8_t inb(uint16_t port) {
   uint8_t ret;
   asm volatile ( "inb %1, %0"
                  : "=a"(ret)
                  : "Nd"(port) );
   return ret;
}

inline void io_wait(void) {
   asm volatile ("jmp 1f\n\t"
                 "1:jmp 2f\n\t"
                 "2:" );
}

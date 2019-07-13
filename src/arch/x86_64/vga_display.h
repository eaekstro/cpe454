/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-04-11
 *
 * VGA display functions
 ***************************************************************************/

#ifndef VGA_DISPLAY_H
#define VGA_DISPLAY_H

   #include <stdbool.h>
   #include "assem.h"

   #define VGA_BASE  0xb8000
   #define VGA_RED   0x4
   #define VGA_WHITE 0xF
   #define VGA_BLACK 0x0
   #define VGA_GREY  0x7

   #define FG(x)     x
   #define BG(x)     x << 4
   #define LINE(x)   (x / 80)

   /*extern void *memset(void *dst, int c, int n);*/

   void VGA_clear(void);
   void VGA_display_char(char ch);
   void VGA_display_str(const char *chPtr);

#endif

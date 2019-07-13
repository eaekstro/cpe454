/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-04-11
 *
 * VGA display functions
 ***************************************************************************/

#include "vga_display.h"
#include "serial.h"

static unsigned short *vgaBuff = (unsigned short *) VGA_BASE;
static int width  = 80;
static int height = 20;
static int cursor = 0;
static unsigned char color = 8 | FG(VGA_RED) | BG(VGA_BLACK);
static unsigned char clrcol = FG(VGA_BLACK) | BG(VGA_BLACK);
static unsigned char curscol = FG(VGA_GREY) | BG(VGA_GREY);

void VGA_clear_line(int line) {
   /*memset(vgaBuff, 0, cursor*sizeof(unsigned short));*/
   int i;
   for (i = 0; i < width; i++)
      vgaBuff[line*width + i] = (clrcol << 8) | '\0';
}

void VGA_copy_line(int to, int from) {
   int i;
   for (i = 0; i < width; i++)
      vgaBuff[to*width + i] = vgaBuff[from*width + i];
}

void scroll() {
   int tempCurs;
   cursor -= width;
   for (tempCurs = 0; tempCurs < cursor; tempCurs += width) {
      VGA_clear_line(LINE(tempCurs));
      VGA_copy_line(LINE(tempCurs), LINE(tempCurs) + 1);
   }
   VGA_clear_line(LINE(cursor));
}

void VGA_clear(void) {
   /*memset(vgaBuff, 0, cursor*sizeof(unsigned short));*/
   bool enable_ints = 0;
   if (interrupts_enabled()) {
      enable_ints = 1;
      CLI();
   }
   
   for (cursor = 0; cursor < width*height; cursor++)
      vgaBuff[cursor] = (clrcol << 8) | '\0';

   cursor = 0;
   
   if (enable_ints)
      STI();
}

void VGA_display_char(char ch) {
   bool enable_ints = 0;
   if (interrupts_enabled()) {
      enable_ints = 1;
      CLI();
   }

   vgaBuff[cursor] = (clrcol << 8) | '\0';
   if (ch == '\n') {
      cursor = (LINE(cursor) + 1) * width;
      if (cursor >= width*height)
         scroll();
   }
   else if ( ch == '\r')
      cursor = LINE(cursor);
   else if (ch == '\b')
      vgaBuff[--cursor] = (clrcol << 8) | '\0';
   else if (ch == '\t')
      cursor += 8 - (cursor % 8);
   else {
      vgaBuff[cursor] = (color << 8) | ch;
      /*if ((cursor % width) < (width - 1))*/
         cursor++;
   }
   vgaBuff[cursor] = (curscol << 8) | '\0';
   /*SER_write(&ch, 1);*/

   if (enable_ints)
      STI();
}

void VGA_display_str(const char *chPtr) {
   char ch;
   while((ch = *chPtr) != '\0') {
      VGA_display_char(ch);
      chPtr++;
   }
}


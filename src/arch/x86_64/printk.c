/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-04-15
 *
 * print functions
 ***************************************************************************/

#include <stdarg.h>
#include "serial.h"

#define MAX_ULONG_DIGITS   20
#define MAX_LONG_DIGITS    19
#define MAX_HEX_DIGITS     16

extern void VGA_display_char(char ch);
extern void VGA_display_str(const char *str);

void print_int(int num);
void print_unsigned(unsigned int num);
void print_hex(unsigned int num);
void print_char(char ch);
void print_long_hex(unsigned long num);
void print_short(short num, char fmt);
void print_long(long num, char fmt);
void print_quad(long long num, char fmt);
void print_str(const char *str);
void print_dec_num(long long num);
void print_uns_num(unsigned long long num);
void print_hex_num(unsigned long long num);

int printk(const char *fmt, ...) {
   va_list argp;
   /*int len = 0;
   char *chPtr = fmt;
   while (*chPtr++ != '\0')
      len++;
   
   SER_write(fmt, len);*/
   va_start(argp, fmt);
   while (*fmt != '\0') {
      if (*fmt == '%') {
         fmt++;
         if (*fmt == '%')
            VGA_display_char('%');
         else if (*fmt == 'd')
            print_int(va_arg(argp, int));
         else if (*fmt == 'u')
            print_unsigned(va_arg(argp, unsigned int));
         else if (*fmt == 'x')
            print_hex(va_arg(argp, unsigned int));
         else if (*fmt == 'c')
            print_char(va_arg(argp, int));
         else if (*fmt == 'p')
            print_long_hex(va_arg(argp, unsigned long));
         else if (*fmt == 'h')
            print_short(va_arg(argp, int), *(++fmt));
         else if (*fmt == 'l')
            print_long(va_arg(argp, long), *(++fmt));
         else if (*fmt == 'q')
            print_quad(va_arg(argp, long long), *(++fmt));
         else if (*fmt == 's')
            print_str(va_arg(argp, char *));
         else
            VGA_display_str("ERROR");
      }
      else
         VGA_display_char(*fmt);

      fmt++;
   }
   va_end(argp);

   return 1;
}

void print_int(int num) {
   print_long(num, 'd');
}

void print_unsigned(unsigned int num) {
   print_long(num, 'u');
}

void print_hex(unsigned int num) {
   print_long(num, 'x');
}

void print_char(char ch) {
   VGA_display_char(ch);
}

void print_long_hex(unsigned long num) {
   print_long(num, 'x');
}

void print_short(short num, char fmt) {
   if (fmt == 'd')
      print_dec_num(num);
   else if (fmt == 'u')
      print_uns_num(num);
   else if (fmt == 'x')
      print_hex_num(num);
   else
      VGA_display_str("ERROR");
}

void print_long(long num, char fmt) {
   if (fmt == 'd')
      print_dec_num(num);
   else if (fmt == 'u')
      print_uns_num(num);
   else if (fmt == 'x')
      print_hex_num(num);
   else
      VGA_display_str("ERROR");
}

void print_quad(long long num, char fmt) {
   if (fmt == 'd')
      print_dec_num(num);
   else if (fmt == 'u')
      print_uns_num(num);
   else if (fmt == 'x')
      print_hex_num(num);
   else
      VGA_display_str("ERROR");
}

void print_str(const char *str) {
   VGA_display_str(str);
}

void print_dec_num(long long num) {
   char str[MAX_LONG_DIGITS + 1];
   int idx = MAX_LONG_DIGITS - 1;
   str[MAX_LONG_DIGITS] = '\0';
   if (num < 0)
      VGA_display_char('-');
   if (num == 0)
      VGA_display_char('0');
   else {
      while (num != 0) {
         str[idx--] = (num % 10) + '0';
         num /= 10;
      }
      VGA_display_str(&(str[idx+1]));
   }
}

void print_uns_num(unsigned long long num) {
   char str[MAX_ULONG_DIGITS + 1];
   int idx = MAX_ULONG_DIGITS - 1;
   str[MAX_ULONG_DIGITS] = '\0';
   if (num == 0)
      VGA_display_char('0');
   else {
      while (num != 0) {
         str[idx--] = (num % 10) + '0';
         num /= 10;
      }
      VGA_display_str(&(str[idx+1]));
   }
}

void print_hex_num(unsigned long long num) {
   char str[MAX_HEX_DIGITS + 1];
   int idx = MAX_HEX_DIGITS - 1;
   long temp;
   str[MAX_HEX_DIGITS] = '\0';
   VGA_display_str("0x");
   if (num == 0)
      VGA_display_char('0');
   else {
      while (num != 0) {
         temp = num % 16;
         str[idx--] = (temp < 10) ? temp + '0' : temp + '7';
         num /= 16;
      }
      VGA_display_str(&(str[idx+1]));
   }
}


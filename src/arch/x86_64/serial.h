/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-04-18
 *
 * Serial output functions
 ***************************************************************************/

#ifndef SERIAL_H
#define SERIAL_H

   #include "assem.h"

   #define SERIAL_PORT  0x3F8
   #define BUFF_SIZE    16

   struct State {
      char buff[BUFF_SIZE];
      char *head, *tail;
   };
   
   void SER_init();
   void set_idle(uint8_t val);
   int SER_write(const char *buff, int len);
   /*static void init_state(struct State *state);
   static void consumer_next(struct State *state);
   static void producer_add_char(char toAdd, struct State *state);*/

#endif

/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-04-18
 *
 * Serial output functions
 ***************************************************************************/

#include "serial.h"

void SER_init(void) {
   outb(0x00, SERIAL_PORT + 1);
   outb(0x80, SERIAL_PORT + 3);
   outb(0x03, SERIAL_PORT + 0);
   outb(0x00, SERIAL_PORT + 1);
   outb(0x03, SERIAL_PORT + 3);
   outb(0xC7, SERIAL_PORT + 2);
   outb(0x0B, SERIAL_PORT + 4);
}

int SER_write(const char *buff, int len) {
   return 1;
}

static void init_state(struct State *state) {
   state->head = &state->buff[0];
   state->tail = &state->buff[0];
}

static int is_transmit_empty() {
   return inb(SERIAL_PORT + 5) & 0x20;
}

static void consume_byte(char ch) {
   while (is_transmit_empty() == 0);

   outb(ch, SERIAL_PORT);
}

static void consumer_next(struct State *state) {
   if (state->head == state->tail)
      return;

   consume_byte(*state->head++);
   if (state->head >= &state->buff[BUFF_SIZE])
      state->head = &state->buff[0];
}

static void producer_add_char(char toAdd, struct State *state) {
   if (state->head == state->tail - 1 || 
         (state->head == &state->buff[0] && state->tail == &state->buff[BUFF_SIZE - 1]) )
      return;

   *state->tail++ = toAdd;
   if (state->tail >= &state->buff[BUFF_SIZE])
      state->tail = &state->buff[0];
}


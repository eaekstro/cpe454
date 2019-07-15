/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-04-18
 *
 * Serial output functions
 ***************************************************************************/

#include "serial.h"

extern int printk(const char *fmt, ...) __attribute__ ((format (printf, 1, 2)));
static void init_state(struct State *state);
static uint8_t is_transmit_empty();
static void consume_byte(char ch);
static void consumer_next(struct State *state);
static int producer_add_char(char toAdd, struct State *state);
static struct State initState;
static uint8_t serial_idle = 1;


void SER_init(void) {
   uint8_t status;
   init_state(&initState);
   outb(0x00, SERIAL_PORT + 1);
   outb(0x80, SERIAL_PORT + 3);
   outb(0x03, SERIAL_PORT + 0);
   outb(0x00, SERIAL_PORT + 1);
   outb(0x03, SERIAL_PORT + 3);
   outb(0xC7, SERIAL_PORT + 2);
   outb(0x0B, SERIAL_PORT + 1);
}

inline void set_idle(uint8_t val) {
   serial_idle = val;
   consumer_next(&initState);
}

int SER_write(const char *buff, int len) {
   int i, loop = 0;
   if (is_transmit_empty() == 0)
      serial_idle = 0;
   else
      serial_idle = 1;

   for (i = 0; i < len; i++) {
      if (producer_add_char(buff[i], &initState) && serial_idle) {
         CLI();
         consumer_next(&initState);
         STI();
      }
   }

   if (serial_idle) {
      CLI();
      consumer_next(&initState);
      STI();
   }

   return 0;
}

static void init_state(struct State *state) {
   state->head = &state->buff[0];
   state->tail = &state->buff[0];
}

static uint8_t is_transmit_empty() {
   return inb(SERIAL_PORT + 5) & 0x20;
}

static void consume_byte(char ch) {
   serial_idle = 0;
   outb(ch, SERIAL_PORT);
}

static void consumer_next(struct State *state) {
   if (state->head == state->tail)
      return;

   consume_byte(*state->head++);
   if (state->head >= &state->buff[BUFF_SIZE])
      state->head = &state->buff[0];
   /*printk("\nHEAD: %d; TAIL: %d\n", (int) (state->head - &state->buff[0]), (int)(state->tail - &state->buff[0]));*/
}

static int producer_add_char(char toAdd, struct State *state) {
   if (state->head - 1 == state->tail || 
         (state->head == &state->buff[0] && state->tail == &state->buff[BUFF_SIZE - 1]) )
      return 1;
   
   *state->tail++ = toAdd;
   if (state->tail >= &state->buff[BUFF_SIZE])
      state->tail = &state->buff[0];
   /*printk("\nHEAD: %d; TAIL: %d\n", (int) (state->head - &state->buff[0]), (int)(state->tail - &state->buff[0]));*/

   return 0;
}



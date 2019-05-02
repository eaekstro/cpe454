/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-04-18
 *
 * Serial output functions
 ***************************************************************************/

#include "assem.h"

#define SERIAL_PORT  0x3F8
#define BUFF_SIZE    16

struct State {
   char buff[BUFF_SIZE];
   char *head, *tail;
};

static void init_state(struct State *state);
static void consumer_next(struct State *state);
static void producer_add_char(char toAdd, struct State *state);

/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-04-15
 *
 * ps2 controller setup functions
 ***************************************************************************/

#include "ps2.h"
#include "assem.h"

static void ps2_poll_write(unsigned char data, unsigned short port) {
   char status = inb(PS2_STATUS);
   while (status & STATUS_OUT_BIT)
      status = inb(PS2_STATUS);

   outb(data, port);
}

static unsigned char ps2_poll_read(void) {
   char status = inb(PS2_STATUS);
   while (!(status & STATUS_IN_BIT))
      status = inb(PS2_STATUS);

   return inb(PS2_DATA_PORT);
}

int ps2_init(void) {
   /*int loop = 0;*/
   char configByte;
   /*ps2_poll_write(DISABLE_PORT1, PS2_CMD_PORT);
   ps2_poll_write(DISABLE_PORT2, PS2_CMD_PORT);*/
   ps2_poll_write(READ_CONFIG, PS2_CMD_PORT);
   configByte = ps2_poll_read();
   
   configByte = configByte & 0x57;
   ps2_poll_write(WRITE_CONFIG, PS2_CMD_PORT);
   ps2_poll_write(configByte, PS2_DATA_PORT);
   /*ps2_poll_write(ENABLE_PORT1, PS2_CMD_PORT);*/
   ps2_poll_write(0xAA, PS2_CMD_PORT);
   if (ps2_poll_read() != 0x55)
      printk("ps2 test FAILED\n");
   /*ps2_poll_write(READ_CONFIG, PS2_CMD_PORT);
   configByte = ps2_poll_read();
   while(!loop);*/

   return 1;
}

int keyboard_init(void) {
   /*int j = 1;
   while(j);*/
   ps2_poll_write(RESET_KB, PS2_DATA_PORT);
   check_status();
   if (ps2_poll_read() != RESET_OK)
      printk("KB reset FAILED\n");

   ps2_poll_write(SET_SCAN_CODE, PS2_DATA_PORT);
   check_status();
   ps2_poll_write(0x02, PS2_DATA_PORT);
   check_status();

   ps2_poll_write(ENABLE_SCANNING, PS2_DATA_PORT);
   check_status();

   return 1;
}

void check_status(void) {
   unsigned char status;
   if ((status = ps2_poll_read()) == RESEND_ACK)
      printk("resend\n");
   else if (status != OK_ACK)
      printk("status not OK\n");
}

char get_ascii() {
   int sc;
   static int shift = 0;
   static const char ascii_lookup[256] = 
   {
         0,   0, '1',  '2',  '3', '4',  '5',  '6', 
       '7', '8', '9',  '0',  '-', '=', '\b', '\t',
       'q', 'w', 'e',  'r',  't', 'y',  'u',  'i',
       'o', 'p', '[',  ']', '\n',   0,  'a',  's',
       'd', 'f', 'g',  'h',  'j', 'k',  'l',  ';',
      '\'', '`',   0, '\\',  'z', 'x',  'c',  'v',
       'b', 'n', 'm',  ',',  '.', '/',    0,    0,
         0, ' ',   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0
   };
   static const char shifted_ascii_lookup[256] = 
   {
         0,   0, '!',  '@',  '#', '$',  '%',  '^', 
       '&', '*', '(',  ')',  '_', '+', '\b', '\t',
       'Q', 'W', 'E',  'R',  'T', 'Y',  'U',  'I',
       'O', 'P', '{',  '}', '\n',   0,  'A',  'S',
       'D', 'F', 'G',  'H',  'J', 'K',  'L',  ':',
      '\"', '~',   0,  '|',  'Z', 'X',  'C',  'V',
       'B', 'N', 'M',  '<',  '>', '?',    0,    0,
         0, ' ',   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0,
         0,   0,   0,    0,    0,   0,    0,    0
   };
   sc = ps2_poll_read();
   if (sc == LSHIFT_PRESSED || sc == RSHIFT_PRESSED)
      shift = 1;
   else if (sc == LSHIFT_RELEASED || sc == RSHIFT_RELEASED)
      shift = 0;
   if (ascii_lookup[sc] == 0)
      return 0;
   
   return (shift) ? shifted_ascii_lookup[sc] : ascii_lookup[sc];
}



/****************************************************************************
 * Eric Ekstrom
 * CPE454
 * 2019-04-15
 *
 * ps2 controller setup functions
 ***************************************************************************/

#define PS2_CMD_PORT    0x64
#define PS2_DATA_PORT   0x60
#define PS2_STATUS      PS2_CMD_PORT

#define STATUS_OUT_BIT  0x02
#define STATUS_IN_BIT   0x01


#define DISABLE_PORT1   0xAD
#define DISABLE_PORT2   0xA7
#define ENABLE_PORT1    0xAE
#define READ_CONFIG     0x20
#define WRITE_CONFIG    0x60

#define RESET_KB        0xFF
#define RESET_OK        0xAA
#define SET_SCAN_CODE   0xF0
#define ENABLE_SCANNING 0xF4
#define RESEND_ACK      0xFE
#define OK_ACK          0xFA

#define LSHIFT_PRESSED  0x2A
#define RSHIFT_PRESSED  0x36
#define LSHIFT_RELEASED 0xAA
#define RSHIFT_RELEASED 0xB6

extern int printk(const char *fmt, ...) __attribute__ ((format (printf, 1, 2)));

void check_status(void);

int ps2_init(void);
int keyboard_init(void);
char get_ascii();

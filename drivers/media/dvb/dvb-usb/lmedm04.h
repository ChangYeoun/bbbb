/* DVB USB compliant linux driver for
 *
 * DM04/QQBOX DVB-S USB BOX	LME2510C + SHARP:BS2F7HZ7395
 *				LME2510C + LG TDQY-P001F
 *				LME2510 + LG TDQY-P001F
 *
 * MVB7395 (LME2510C+SHARP:BS2F7HZ7395)
 * SHARP:BS2F7HZ7395 = (STV0288+Sharp IX2505V)
 *
 * MVB001F (LME2510+LGTDQT-P001F)
 * LG TDQY - P001F =(TDA8263 + TDA10086H)
 *
 * MVB0001F (LME2510C+LGTDQT-P001F)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation,  version 2.
 * *
 * see Documentation/dvb/README.dvb-usb for more information
 */
#ifndef _DVB_USB_LME2510_H_
#define _DVB_USB_LME2510_H_

/* Streamer &  PID
 *
 * Note:	These commands do not actually stop the streaming
 *		but form some kind of packet filtering/stream count
 *		or tuning related functions.
 *  06 XX
 *  offset 1 = 00 Enable Streaming
 *
 *
 *  PID
 *  03 XX XX  ----> reg number ---> setting....20 XX
 *  offset 1 = length
 *  offset 2 = start of data
 *  end byte -1 = 20
 *  end byte = clear pid always a0, other wise 9c, 9a ??
 *
*/
#define LME_ST_ON_W	{0x06, 0x00}
#define LME_CLEAR_PID   {0x03, 0x02, 0x20, 0xa0}
#define LME_ZERO_PID	{0x03, 0x06, 0x00, 0x00, 0x01, 0x00, 0x20, 0x9c}
#define LME_ALL_PIDS	{0x03, 0x06, 0x00, 0xff, 0x01, 0x1f, 0x20, 0x81}

/*  LNB Voltage
 *  07 XX XX
 *  offset 1 = 01
 *  offset 2 = 00=Voltage low 01=Voltage high
 *
 *  LNB Power
 *  03 01 XX
 *  offset 2 = 00=ON 01=OFF
 */

#define LME_VOLTAGE_L	{0x07, 0x01, 0x00}
#define LME_VOLTAGE_H	{0x07, 0x01, 0x01}
#define LNB_ON		{0x3a, 0x01, 0x00}
#define LNB_OFF		{0x3a, 0x01, 0x01}

/* Initial stv0288 settings for 7395 Frontend */
static u8 s7395_inittab[] = {
	0x01, 0x15,
	0x02, 0x20,
	0x03, 0xa0,
	0x04, 0xa0,
	0x05, 0x12,
	0x06, 0x00,
	0x09, 0x00,
	0x0a, 0x04,
	0x0b, 0x00,
	0x0c, 0x00,
	0x0d, 0x00,
	0x0e, 0xc1,
	0x0f, 0x54,
	0x11, 0x7a,
	0x12, 0x03,
	0x13, 0x48,
	0x14, 0x84,
	0x15, 0xc5,
	0x16, 0xb8,
	0x17, 0x9c,
	0x18, 0x00,
	0x19, 0xa6,
	0x1a, 0x88,
	0x1b, 0x8f,
	0x1c, 0xf0,
	0x20, 0x0b,
	0x21, 0x54,
	0x22, 0xff,
	0x23, 0x01,
	0x28, 0x46,
	0x29, 0x66,
	0x2a, 0x90,
	0x2b, 0xfa,
	0x2c, 0xd9,
	0x30, 0x0,
	0x31, 0x1e,
	0x32, 0x14,
	0x33, 0x0f,
	0x34, 0x09,
	0x35, 0x0c,
	0x36, 0x05,
	0x37, 0x2f,
	0x38, 0x16,
	0x39, 0xbd,
	0x3a, 0x0,
	0x3b, 0x13,
	0x3c, 0x11,
	0x3d, 0x30,
	0x40, 0x63,
	0x41, 0x04,
	0x42, 0x20,
	0x43, 0x00,
	0x44, 0x00,
	0x45, 0x00,
	0x46, 0x00,
	0x47, 0x00,
	0x4a, 0x00,
	0x50, 0x10,
	0x51, 0x36,
	0x52, 0x21,
	0x53, 0x94,
	0x54, 0xb2,
	0x55, 0x29,
	0x56, 0x64,
	0x57, 0x2b,
	0x58, 0x54,
	0x59, 0x86,
	0x5a, 0x00,
	0x5b, 0x9b,
	0x5c, 0x08,
	0x5d, 0x7f,
	0x5e, 0xff,
	0x5f, 0x8d,
	0x70, 0x0,
	0x71, 0x0,
	0x72, 0x0,
	0x74, 0x0,
	0x75, 0x0,
	0x76, 0x0,
	0x81, 0x0,
	0x82, 0x3f,
	0x83, 0x3f,
	0x84, 0x0,
	0x85, 0x0,
	0x88, 0x0,
	0x89, 0x0,
	0x8a, 0x0,
	0x8b, 0x0,
	0x8c, 0x0,
	0x90, 0x0,
	0x91, 0x0,
	0x92, 0x0,
	0x93, 0x0,
	0x94, 0x1c,
	0x97, 0x0,
	0xa0, 0x48,
	0xa1, 0x0,
	0xb0, 0xb8,
	0xb1, 0x3a,
	0xb2, 0x10,
	0xb3, 0x82,
	0xb4, 0x80,
	0xb5, 0x82,
	0xb6, 0x82,
	0xb7, 0x82,
	0xb8, 0x20,
	0xb9, 0x0,
	0xf0, 0x0,
	0xf1, 0x0,
	0xf2, 0xc0,
	0xff, 0xff,
};
#endif

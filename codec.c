/*
 * File:   codec.c
 * Author: MTurner
 *
 * Created on Feb 25th 2020
 */
#include "codec.h"
void buildMessage(long status, char *buffr, char *out)
{
    int crcInt = 0;
	int i = 0;
	//Start Byte
	out[0] = 0x01; // start ☺
	//Status Byte
	out[1] = 0; // shift and mask to separate out the bytes
	out[2] = 0;
	out[3] = status;
	//Blob length
    long length = 0;
	length = strlen(buffr); // buffr must be null terminated (it is)
	out[4] = (length >> 8) && 0xFF;
	out[5] = (length >> 0) && 0xFF;
	//CSV blob
	for(i = 0; i < strlen(buffr); i++)
	{
		out[i+6] = buffr[i];
	}	// add data to message
	//CRC
    crcInt = crc16(out, length+6);
    out[length+6] = (char)(crcInt >> 8);
    out[length+7] = (char)(crcInt >> 0);
	return;
}

unsigned short crc16(char *ptr, int count)
{
   int  crc;
   char i;
   crc = 0;
   while (--count >= 0)
   {
      crc = crc ^ (int) *ptr++ << 8;
      i = 8;
      do
      {
         if (crc & 0x8000)
            crc = crc << 1 ^ 0x1021;
         else
            crc = crc << 1;
      } while(--i);
   }
   return (crc);
}

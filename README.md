# StampCodec

This C library contains the function used to build the codec message from data

## capture file
This file is an example of the data stream captured using realterm

The format goes like this
- Start byte (1B)
- Status bytes (3B)
- Blob length (1B)
- CSV Blob (length changes at runtime)
- CRC16 Xmodem	(2B)

## Start Byte
This is the start of header byte, 0x01. This was chosen to be congruent with the Xmodem protocol. Also, it makes a smiley face

## Status bytes
These bytes are the alarm status bytes, with 12 sets of 2 bits. 0b00 is green, 0b01 is yellow, 0b10 is null and 0b11 is red. We'll fill in from the least significant bits so we're only interested in the final nibble of byte 3. Channel 0 in red alarm and channel 1 in yellow would be 0x00 0x00 0x06
The reason for the ordering of the alarm states is that our yellow detection scheme can go back to un-alarm after saturation, and the sensor's alarm will remain red, even in clean air. This is the null state and should prevent false positives
## Blob length
This is the length of the debug data, not the entire message. The entire message should be 7+N bytes

## CSV blob
This is datalogging information and not covered in this scope

## CRC
The final two bytes are the CRC of the preceeding message using the Xmodem protocol. 
See codec.c for real implementation
Helpful resources below:
https://stackoverflow.com/questions/17196743/crc-ccitt-implementation
https://crccalc.com/

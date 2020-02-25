# StampCodec

This C library contains the function used to build the codec message from data

The format goes like this
- Start byte (1B)
- Status bytes (3B)
- Blob length (1B)
- CSV Blob (length changes at runtime)
- CRC16 Xmodem	(2B)

## Start Byte
This is the start of header byte, 0x01. This was chosen to be congruent with the Xmodem protocol. Also, it makes a smiley face

## Status bytes
These bytes are the alarm status bytes, with 12 sets of 2 bits. 0b00 is green, 0b01 is yellow, 0b10 is red and 0b11 is null. We'll fill in from the least significant bits so we're only interested in the final nibble of byte 3. Channel 0 in red alarm and channel 1 in yellow would be 0x00 0x00 0x06

## Blob length
This is the length of the debug data, not the entire message. The entire message should be 7+N bytes

## CSV blog
This is datalogging information and not covered in this scope

## CRC
The final two bytes are the CRC of the preceeding message using the Xmodem protocol. 
See codec.c for real implementation
Helpful resources below:
https://stackoverflow.com/questions/17196743/crc-ccitt-implementation
https://crccalc.com/

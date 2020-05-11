# StampCodec

This ICD contains the formatting used to build the MOSA's message, the C implementation and data stream files.  
The MOSA powers up and calibrates, then immediately starts sending data at a rate of approximately a message every .7 seconds using UART and USB if available. If UART is used, it will be formatted using the codec below. USB omits the packet overhead and only sends the 'blob' data. 
The MOSA does not need to accept any commands to send data.

## Data Format Specification
- Start byte (1B)
- Status bytes (3B)
- Blob length (2B)
- CSV Blob (length changes at runtime)
- CRC16 Xmodem	(2B)

## Start Byte
This is the start of header byte, 0x01. This was chosen to be congruent with the Xmodem protocol. Also, it makes a smiley face

## Status bytes
These bytes are the alarm status bytes, with 12 sets of 2 bits. 0b00 is green, 0b01 is yellow, 0b10 is null and 0b11 is red. We'll fill in from the least significant bits so we're only interested in the final nibble of byte 3. Channel 0 in red alarm and channel 1 in yellow would be 0x00 0x00 0x07
The reason for the ordering of the alarm states is that our yellow detection scheme can go back to un-alarm after saturation, and the sensor's alarm will remain red, even in clean air. This is the null state and should prevent false positives
## Blob length
This is the length of the debug data, not the entire message. The entire message should be 8+N bytes

## CSV blob
This is datalogging information and not covered in this scope

## CRC
The final two bytes are the CRC of the preceeding message using the Xmodem protocol. 
See codec.c for real implementation
Helpful resources below:
https://stackoverflow.com/questions/17196743/crc-ccitt-implementation
https://crccalc.com/


## Capture files
The files included in this repo is are examples of the data stream captured using realterm. capture.ascii is the data being shown as ascii characters, so a blob length of 37 bytes would show as the character %. The capturehex.txt file is the text representation of the data, where 37 decimal is shown as 25 hex. These datastreams can be used to validate the decoding of the data
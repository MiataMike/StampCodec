
/* 
 * File:PioConfig.h   
 * Author: MTurner
 * Comments:
 * Revision history: first header!
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef CODEC_H
#define	CODEC_H

#include <stdlib.h>
#include <string.h>

//pass the data into this function to create the message that can be output to the sendUART() function
void buildMessage(long status, char *buf, char *out);


//This gets called by buildMessage to calculate the CRC once everything is built
unsigned short crc16(char *ptr, int count);







#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* CODEC_H */



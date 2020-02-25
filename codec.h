
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


//pass the data into this function to create the message that can be output to the sendUART() function
char* buildMessage(int status, char* buf);


//This gets called by buildMessage to calculate the CRC once everything is built
int calcCRC(char* str);









#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* CODEC_H */



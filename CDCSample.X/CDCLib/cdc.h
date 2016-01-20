#ifndef CDC_H
#define	CDC_H

#include <xc.h>
#include <usb_config.h>

void systemInit();
int update();
void cdcPuts(char *data);
void cdcPut(char *data,int length);
unsigned char cdcGets(unsigned char *data,int length);
#endif


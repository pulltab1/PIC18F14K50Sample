#include <xc.h>


#pragma config FOSC = IRC
#pragma config USBDIV = OFF, CPUDIV = NOCLKDIV
#pragma config IESO  = OFF, FCMEN = OFF, PLLEN  = ON
#pragma config BORV  = 30,  BOREN = OFF, PWRTEN = OFF
#pragma config WDTPS = 32768, WDTEN = OFF
#pragma config MCLRE = OFF, HFOFST = OFF, XINST  = OFF
#pragma config BBSIZ = OFF, LVP    = OFF, STVREN = ON
#pragma config CP1  = OFF, CP0  = OFF, CPD  = OFF, CPB  = OFF
#pragma config WRT1 = OFF, WRT0 = OFF, WRTB = OFF, WRTC = OFF
#pragma config EBTR1 = OFF, EBTR0 = OFF, EBTRB  = OFF

void i2c_wait(void){
    while(( SSPCON2 & 0x1F )||( SSPSTATbits.R_nW ));
}

void i2c_enable(void){
    SSPSTAT = 0b10000000;
    SSPADD = 9;
    SSPCON1 = 0b00101000;
}

void i2c_disable(void){
    SSPCON1 = 0b00001000;
}

void i2c_start(void){
    SSPCON2bits.SEN = 1;
    i2c_wait();
}
void i2c_repeat(void){
    SSPCON2bits.RSEN = 1;
    i2c_wait();
}

void i2c_stop(void){
    SSPIF = 0;
    PEN = 1;
    while(PEN);
    SSPIF = 0;
}


void i2c_send(const unsigned char data){
    SSPBUF = data;
    i2c_wait();
}

unsigned char i2c_recv(void){
    SSPCON2bits.RCEN = 1;
    while (!SSPSTATbits.BF);
    return (SSPBUF);
}
void i2c_sendNACK(void){
    ACKDT = 1;
	ACKEN = 1;
	while (ACKEN);
}
void i2c_sendACK(void){
    ACKDT = 0;
	ACKEN = 1;
	while(ACKEN);
}

unsigned char i2c_checkACK(void){
    unsigned char i2c_data;
	if(ACKSTAT)i2c_data = 0xFF;
    else i2c_data = 0x00;
	return(i2c_data);
}
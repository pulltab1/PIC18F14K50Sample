#ifndef I2C_H
#define	I2C_H

void i2c_enable(void);
void i2c_disable(void);
void i2c_start(void);
void i2c_repeat(void);
void i2c_stop(void);
void i2c_wait(void);
void i2c_send(const unsigned char data);
unsigned char i2c_recv();
void i2c_sendNACK();
void i2c_sendACK();
unsigned char i2c_checkACK();

#endif

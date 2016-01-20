#ifndef LCD_H
#define	LCD_H


// LCD device I2C Address
#define LCD_I2C_ADDR	0x3E

// LCD Contrast (ST7032)
#define LCD_CONTRAST		0x28

void lcd_send_command(unsigned char data);
void lcd_send_data(unsigned char data);
void lcd_init(void);
void lcd_putch(const unsigned char c);
void lcd_puts(const unsigned char *s);
void lcd_cmd(const unsigned char cmd);
void lcd_clear(void);
void lcd_set_cursor(const unsigned char pos);
void putch(unsigned char ch);
#endif


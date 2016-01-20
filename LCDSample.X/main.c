#include <xc.h>
#include <stdio.h>
#include <i2c.h>
#include <lcd.h>

void main(void){
    int hoge=114;
    
    //i2c初期化
    i2c_enable();   //i2cを有効
    lcd_init();     //LCDを初期化
    
    
    while(1){
        lcd_set_cursor(0);  //LCD表示位置を最初に設定
        printf("Hello");    //文字出力
        lcd_set_cursor(0x40);//LCD表示位置を二行目に設定
        printf("%d",hoge);
    }
    return;
}
#include <xc.h>

//周波数に合わせる(4Mhz))
#define _XTAL_FREQ 4000000

//コンフィギュレーション(おまじない)
#pragma config FOSC   = IRC, PLLEN  = ON,  FCMEN  = OFF
#pragma config IESO   = OFF, USBDIV = OFF, CPUDIV = NOCLKDIV
#pragma config PWRTEN = OFF, BOREN  = OFF, WDTEN  = OFF
#pragma config HFOFST = OFF, MCLRE  = OFF
#pragma config STVREN = ON,  BBSIZ  = OFF, LVP    = OFF
#pragma config XINST  = OFF
#pragma config CP0    = OFF, CP1    = OFF, CPB    = OFF
#pragma config WRT0   = OFF, WRT1   = OFF, WRTB   = OFF, WRTC   = OFF
#pragma config EBTR0  = OFF, EBTR1  = OFF, EBTRB  = OFF

void main(void)
{
    //周波数設定
    OSCCON = 0b01010010;
    
    //入出力処理
    LATCbits.LATC0      = 0;    //C0からの出力をlowに(off)
    TRISCbits.TRISC0    = 0;    //C0を出力用ポートにする
    
    while(1)
    {
        LATCbits.LATC0  = 1;    //C0からの出力をhighに(on)
        __delay_ms(100);        //100ms待つ
        LATCbits.LATC0  = 0;
        __delay_ms(100);
    }
    return;
}

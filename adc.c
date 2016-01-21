#include <xc.h>
#include "adc.h"

void ADC_Enable(ADC_CHANNEL channel)
{
    switch(channel){
        case ADC_CHANNEL_RA4:
            TRISAbits.RA4=1;
            ANSELbits.ANS3=1;
            break;
        case ADC_CHANNEL_RC0:
            TRISCbits.RC0=1;
            ANSELbits.ANS4=1;
            break;
        case ADC_CHANNEL_RC1:
            TRISCbits.RC1=1;
            ANSELbits.ANS5=1;
            break;
        case ADC_CHANNEL_RC2:
            TRISCbits.RC2=1;
            ANSELbits.ANS6=1;
            break;
        case ADC_CHANNEL_RC3:
            TRISCbits.RC3=1;
            ANSELbits.ANS7=1;
            break;
        case ADC_CHANNEL_RC6:
            TRISCbits.RC0=6;
            ANSELHbits.ANS8=1;
            break;
        case ADC_CHANNEL_RC7:
            TRISCbits.RC7=1;
            ANSELHbits.ANS9=1;
            break;
        case ADC_CHANNEL_RB4:
            TRISBbits.RB4=1;
            ANSELHbits.ANS10=1;
            break;
        case ADC_CHANNEL_RB5:
            TRISBbits.RB5=1;
            ANSELHbits.ANS11=1;
            break;
    }
    ADCON2 = 0b00101100;
    ADCON1 = 0b00000000;
    ADCON0 = (channel<<2)|0b00000001;
}

unsigned int ADC_Read()
{
    ADCON0bits.GO = 1;      // AD変換開始
    while(ADCON0bits.GO);   // AD変換終了待ち
    return (ADRESH<<5)|ADRESL;      // AD変換結果取得
}
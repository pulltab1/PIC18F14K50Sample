#include <xc.h>
#include <stdio.h>
#include <cdc.h>

void main(void)
{
    unsigned char buff[CDC_DATA_OUT_EP_SIZE];
    unsigned char text[256];
    int length;
    
    //システムの初期化
    systemInit();
    
    while(update()){//ループ毎処理
        length=cdcGets(buff,sizeof(buff));//PC側から文字を取得
        if(length>0){//もし何か取得できていれば
            sprintf(text, "%d;%s\n",length,buff);//文字数と文字列を表示するようにする
            cdcPuts(text);//転送(連続で呼び出せないので出すときは一気に)
            
        }
    }
}
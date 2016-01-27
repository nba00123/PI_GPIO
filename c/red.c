#include <wiringPi.h>
#include <stdlib.h>
#include "gpio_pi.h"
#include "stdio.h"


int inputPin=4; // 定义超声波信号接收接口
int outputPin=5; // 定义超声波信号发出接口
int ledpin=2;


int setup(){
    if( wiringPiSetup() == -1 )
        exit( 1 );
    pinMode( inputPin, INPUT );
    pinMode( outputPin, OUTPUT );
    pinMode( ledpin, OUTPUT );
}
int loop(){
    int lv;
    lv=digitalRead(inputPin);
    digitalWrite(ledpin,lv);
}
int main()
{
    
     setup();

    while(1)
    {
       loop();
    }

    return 0;
}
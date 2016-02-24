#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <stdlib.h>
#include "wiringSerial.h"
#include "piLib.c"
// Trig接Arduino板的Digital 5口，触发测距；Echo接Digital 4口，接收距离信号。
// int inputPin=4; // 定义超声波信号接收接口
int outputPin=5; // 定义超声波信号发出接口
// int ledpin=2;
char binbuf[32];
int msg=7;
int idx=0;
int setup()
{
    int fd ;
    int count ;
    if ((fd = serialOpen ("/dev/ttyAMA0", 9600)) < 0)
    {
        fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
        return 1 ;
    }

    if (wiringPiSetup () == -1)
    {
        fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno)) ;
        return 1 ;
    }
    // serialOpen(9600)
    // Serial.begin(9600);
    // pinMode(ledpin,OUTPUT);
    // pinMode(inputPin, INPUT);
    pinMode(outputPin, OUTPUT);
}

void writeContent(int msg){
    int t=0;
    for(t;t<8;t++){
        digitalWrite(outputPin, LOW); // 使发出发出超声波信号接口低电平2μs
        delayMicroseconds(2);
        if(t==4){
            digitalWrite(outputPin, LOW); 
        }else{
            digitalWrite(outputPin, HIGH); // 使发出发出超声波信号接口高电平10μs，这里是至少10μs
        }
        
        delayMicroseconds(2);
    }
    digitalWrite(outputPin, LOW); // 保持发出超声波信号接口低电平
}
void writeChecker(int len){
    int t=0;
    for(t;t<len;t++){
        digitalWrite(outputPin, LOW); // 使发出发出超声波信号接口低电平2μs
        delayMicroseconds(2);
        digitalWrite(outputPin, HIGH); // 使发出发出超声波信号接口高电平10μs，这里是至少10μs
        delayMicroseconds(10);
        
    }
    digitalWrite(outputPin, LOW); // 保持发出超声波信号接口低电平
}
void loop()
{
    int len=2;
    writeChecker(len);
    writeContent(msg);
    //writeChecker(len);
    printf("-->%d\n", idx);
}
int main(){
    printf("%s\n", "315m测试");
    int err;
    err=setup();
    if(err==1)return -1;
    idx=0;
    while(1){
        loop();
        delayMicroseconds(1000000);
        idx++;
    }
}
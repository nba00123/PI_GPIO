#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <stdlib.h>
#include "wiringSerial.h"
#include "piLib.c"
// Trig接Arduino板的Digital 5口，触发测距；Echo接Digital 4口，接收距离信号。
int inputPin=4; // 定义超声波信号接收接口
int outputPin=5; // 定义超声波信号发出接口
int ledpin=2;
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
	pinMode(ledpin,OUTPUT);
	pinMode(inputPin, INPUT);
	pinMode(outputPin, OUTPUT);
}
void loop()
{
	digitalWrite(outputPin, LOW); // 使发出发出超声波信号接口低电平2μs
	delayMicroseconds(2);
	digitalWrite(outputPin, HIGH); // 使发出发出超声波信号接口高电平10μs，这里是至少10μs
	delayMicroseconds(10);
	digitalWrite(outputPin, LOW); // 保持发出超声波信号接口低电平
	int distance = pulseIn(inputPin, HIGH, 100000); // 读出脉冲时间
	distance= distance/58; // 将脉冲时间转化为距离（单位：厘米）
	printf("\rdis=%dcm    ",distance); //输出距离值 
	delay(50); 
	if (distance >=50)
	{//如果距离大于50厘米小灯亮起
		digitalWrite(ledpin,HIGH);
	}//如果距离小于50厘米小灯熄灭
	else
		digitalWrite(ledpin,LOW);
}

// int pulseIn(int pin,int state){
// 	int a;//从这开始计时;
// 	// printf("%d %d\n", state,digitalRead(pin));
// 	while(state!=digitalRead(pin)){
// 		a=clock();
// 	};
// 	while(state==digitalRead(pin)){
		
// 	};

// 	int b=clock();//到这结束
// 	int c=b-a;//算出来的单位是毫秒
// }
int main(){
	printf("%s\n", "距离测试");
	int err;
	err=setup();
	if(err==1)return -1;
	while(1){
		loop();
	}
}
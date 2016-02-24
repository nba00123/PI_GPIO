#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <stdlib.h>
#include "wiringSerial.h"
#include "piLib.c"
// Trig接Arduino板的Digital 5口，触发测距；Echo接Digital 4口，接收距离信号。
int inputPin=4; // 定义超声波信号接收接口
//int outputPin=5; // 定义超声波信号发出接口
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
	//pinMode(outputPin, OUTPUT);
}
void loop()
{
	
	int t = pulseIn(inputPin, HIGH, 100000); // 读出脉冲时间
	printf("%d\n",t);
	
}

int main(){
	printf("%s\n", "距离测试");
	int err;
	err=setup();
	if(err==1)return -1;
	while(1){
		loop();
	}
}
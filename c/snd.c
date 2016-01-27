#include <wiringPi.h>
#include <stdlib.h>
#include "gpio_pi.h"
#include "stdio.h"
int main()
{
    int i;

    if( wiringPiSetup() == -1 )
        exit( 1 );

 
    pinMode( 4, INPUT ); 

    while(1)
    {
        i=digitalRead(4);
        printf("%d", i);
    }

    return 0;
}
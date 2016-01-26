#include <wiringPi.h>
#include <stdlib.h>
#include "gpio_pi.h"

int main()
{
    int i;

    if( wiringPiSetup() == -1 )
        exit( 1 );

 
    pinMode( RPI_13, OUTPUT ); 

    while(1)
    {
        digitalWrite( RPI_13, HIGH );
        delay( 200 );
        digitalWrite( RPI_13, LOW );
        delay( 200 );
    }

    return 0;
}
for Raspberry Pi GPIO test
#setup ENV
###prepare
 ```shell
git clone git://git.drogon.net/wiringPi
cd wiringPi
./build

```

###test
```c
/********** test.c ***************/
#include <wiringPi.h>
#include <stdlib.h>

int main()
{
    int i;

    if( wiringPiSetup() == -1 )
        exit( 1 );

    pinMode( 0, OUTPUT ); 
    pinMode( 1, OUTPUT ); 
    pinMode( 2, OUTPUT ); 
    pinMode( 3, OUTPUT ); 

    for(i = 0; i < 40; i++)
    {
        digitalWrite( i % 4, HIGH );
        delay( 200 );
        digitalWrite( i % 4, LOW );
        delay( 200 );
    }

    return 0;
}
/********** test.c ***************/
```
###build&run

```shell
cc -o test test.c -L/usr/local/lib -lwiringPi
sudo ./test
```

###more
go to see

[gpio c with winringPi](http://xmcore.net:8084/article/22/gpioc.html)

[winringPi API](https://projects.drogon.net/raspberry-pi/wiringpi/functions/)
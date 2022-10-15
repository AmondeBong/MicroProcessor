#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0xFF;
    while (1)
    {
        PORTB = 0xA0;    // 1011 0000
        _delay_ms(2000); // 2초로 설정
        PORTB = 0x28;    // 0010 1000
        _delay_ms(2000); // 2초로 설정
        PORTB = 0x0A;    // 0000 1010
        _delay_ms(2000); // 2초로 설정
        PORTB = 0x82;    // 1000 0010
        _delay_ms(2000); // 2초로 설정
    }
}
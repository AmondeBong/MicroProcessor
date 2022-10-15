#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main()
{
    DDRB |= 0xFF;  // 8개의 핀 모두 출력(1)으로 설정
    DDRF &= 0x40;  // PF2만을 입력(0)으로 설정
    PORTF |= 0x40; // PF2 핀에 연결된 외부 풀다운 저항 사용

    char state_pre = 0, state_cur; //이전 패턴과 현재 패턴 저장(버튼 상태 읽기용)
    char pattern_value = 0xA0;     //첫번째 패턴

    void turnLed(char pattern)
    {
        char pattern_val = pattern;

        while (pattern_val != 0x02)
        { // 마지막 4번째 패턴이 아닌경우 while문으로 반복적으로 2칸씩 옮겨지며 led 출력
            PORTB = pattern_val;
            _delay_ms(1000);
            pattern_val >>= 2;
        }
        if (pattern_val == 0x02) // 맨 마지막 패턴의 경우 없어지는 비트가 존재하므로 예외처리
        {
            pattern_val = 0x82;
            PORTB = pattern_val;
            _delay_ms(1000);
        }
    }

    while (1)
    {
        state_cur = (PINF & 0x04) >> 2; //버튼 상태 읽기
        //버튼이 눌러지지 않은 상태에서 눌러진 상태로 변하는 경우
        if (state_cur == 1 && state_pre == 0)
        {
            _delay_ms(30); // 0.03 지연후 동작
            turnLed(pattern_value);
        }

        state_pre = state_cur;
    }

    return 0;
}
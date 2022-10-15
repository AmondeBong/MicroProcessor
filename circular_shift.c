int main()
{

    char circular_shift_right(char pattern)
    {

        char new_pattern = pattern >> 2; // 오른쪽으로 두칸 이동

        if (pattern == 0x0A)
        {
            char LSB = pattern & 0x02;       //곧 사라질 1번 led 보존
            char MSB = LSB << 6;             // 맨 왼쪽으로 이동
            char new_pattern = pattern >> 2; // 오른쪽으로 두칸 이동
            new_pattern |= MSB;              // 사라진 패턴을 추가
        }

        return new_pattern; //
    }
}
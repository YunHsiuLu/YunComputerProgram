#include <stdio.h>

int main()
{
    // 0.5 + 2.7 * 3.2 - 6.8 / 2.4
    float a = 0.5;
    float b = 2.7;
    float c = 3.2;
    float d = 6.8;
    float e = 2.4;
    float answer = 0.0;

    answer = a + b * c - d / e;

    printf( "The answer is %f\n", answer );
    printf( "The answer is %f\n", 0.5 + 2.7 * 3.2 - 6.8 / 2.4 );

    return 0;
}

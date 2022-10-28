#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t a = 0;
    int32_t b = 0;
    int32_t c = 0;
    int32_t d = 0;
    int32_t e = 0;
    int32_t sum = 0;
    float average = 0.0;

    printf("Please enter five integers:\n");
    scanf( "%d %d %d %d %d", &a, &b, &c, &d, &e );

    sum = a + b + c +d + e;
    average = sum / 5;

    printf( "Average is : %f\n", average );

    return 0;
}

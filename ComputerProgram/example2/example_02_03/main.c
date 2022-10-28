#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t a = 2;
    int32_t b = 3;
    int32_t sum = 0;

    printf("Please enter the first integer:\n");
    scanf( "%d", &a );
    printf("Please enter the second integer:\n");
    scanf( "%d", &b );
    sum = a + b;
    printf( "%d + %d = %d\n", a, b, sum );
    return 0;
}

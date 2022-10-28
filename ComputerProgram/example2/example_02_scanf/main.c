#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t a = 0;
    int32_t b = 0;
    int32_t sum = 0;

    printf("Please enter two integers:\n");
    scanf( "%d,%d", &a, &b );
    sum = a + b;
    printf( "%d + %d = %d\n", a, b, sum );
    return 0;
}

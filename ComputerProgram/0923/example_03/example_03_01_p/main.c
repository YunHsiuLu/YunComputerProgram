#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t a = 0;
    int32_t b = 0;

    printf("Please enter two integers:\n");
    scanf( "%d %d", &a, &b );

    printf( a > b ? "a is greater than b\n" :
                    "a is not greater than b\n" );

    return 0;
}

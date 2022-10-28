#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t a = 0;
    int32_t b = 0;

    printf("Please enter two integers:\n");
    scanf( "%d %d", &a, &b );

    if( a > b )
    {
        printf( "%d is greater than %d\n", a, b );
    }

    if( a < b )
    {
        printf( "%d is smaller than %d\n", a, b );
    }

    if( a == b )
    {
        printf( "%d is equal to %d\n", a, b );
    }

    return 0;
}

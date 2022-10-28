#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Please enter two integers!\n");

    int integer01 = 0, integer02 = 0;

    scanf( "%d %d", &integer01, &integer02 );

    printf( "%d + %d = %d\n", integer01, integer02, integer01 + integer02 );

    return 0;
}

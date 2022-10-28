#include <stdio.h>

int main()
{
    long long a = 0;
    short b = 0;
    float c = 0.0;

    printf( "Size of int is %d %d\n", sizeof( int ), sizeof( a ) );
    printf( "Size of short is %d %d\n", sizeof( short ), sizeof( b ) );
    printf( "Size of float is %d %d\n", sizeof( float ), sizeof( c ) );

    return 0;
}

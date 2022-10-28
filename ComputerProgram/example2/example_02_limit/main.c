#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Min Integer:\t%d\nMax Integer:\t%d\n", INT_MIN, INT_MAX );
    printf("Min Unsigned Integer:\t%d\nMax Unsigned Integer:\t%u\n", 0, UINT_MAX );
    printf("Min Long Integer:\t%ld\nMax Long Integer:\t%ld\n", LONG_MIN, LONG_MAX );
    printf("Min Unsigned Long Integer:\t%d\nMax Unsigned Long Integer:\t%lu\n", 0, ULONG_MAX );
    return 0;
}

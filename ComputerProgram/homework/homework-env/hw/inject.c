#include <stdio.h>

__attribute__((constructor)) static void _TA_inject() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}
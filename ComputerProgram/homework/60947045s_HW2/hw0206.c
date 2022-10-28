#include <stdio.h>
#include <stdint.h>

uint32_t ui = 0;
uint16_t us = 0;
uint8_t  u_ = 0;
int32_t si = -1;
int16_t ss = -1;

int main()
{
	int64_t r1 = ui + si;
	int64_t r2 = us + si;
	int64_t r3 = ui + ss;
	printf("%ld %ld %ld\n", r1, r2, r3);
}

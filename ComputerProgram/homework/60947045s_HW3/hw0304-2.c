#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "4/hanoi.h"

int main() {
	int8_t n = 0;
	printf("This is iterative mode!\n");
	printf("Please enter the disk number (2-20): ");
	scanf("%hhd", &n);
	//printf("Total steps are: %d\n", (int)(pow(2,n)-1));
	Hanoi_iter(n, 1, 2, 3);
	return 0;
}

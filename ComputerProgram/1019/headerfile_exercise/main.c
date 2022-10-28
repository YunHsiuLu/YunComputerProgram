#include <stdio.h>
#include "swap.h"

int main() {
	int a = 3, b = 5;
	printf("a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
	return 0;
}

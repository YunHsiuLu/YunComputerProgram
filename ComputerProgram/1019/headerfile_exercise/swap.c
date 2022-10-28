#include "swap.h"
// purpose: we can only provide the swap.o and swap.h
// for others, and they don't know the source code.

void swap(int *a, int *b) {
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

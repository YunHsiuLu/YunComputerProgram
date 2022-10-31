#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include "iter.h"

int8_t find_disk(int32_t i, int8_t n) {
	int32_t step = (int32_t)pow(2, n) - 1;
	int8_t cnt = 1;
	while (cnt <= n) {
		if (i % (int)pow(2, n-cnt) == 0) return (n-cnt+1);
		cnt++;
	}
	
}

void Hanoi_iter(int8_t n, int8_t A, int8_t B, int8_t C) {
	int32_t step = (int32_t)pow(2, n) - 1;
	int32_t i = 1;
	int8_t disk = 0;
	int8_t start = A, end = B, temp = C;
	int32_t *index = malloc(n);
	for (int8_t t = 0; t < n; t++) index[t] = 0;
	int8_t order_odd[3] = {2, 3, 1}, order_even[3] = {3, 2, 1};
	if (n % 2 == 0) {
		order_odd[0] = 3;
		order_odd[1] = 2;
		order_odd[2] = 1;
		order_even[0] = 2;
		order_even[1] = 3;
		order_even[2] = 1;
	}
	while (i <= step) {
		disk = find_disk(i, n);
		if (disk % 2 == 0) printf("move disk %hhd to rod %hhd\n", disk, order_even[index[disk-1]%3]);
		else printf("move disk %hhd to rod %hhd\n", disk, order_odd[index[disk-1]%3]);
		index[disk-1]++;
		i++;
	}
	free(index);
}

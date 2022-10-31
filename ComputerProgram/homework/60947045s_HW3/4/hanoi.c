#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "hanoi.h"

void Hanoi_recu(int8_t n, int8_t *arr, int8_t A, int8_t B, int8_t C) {
	if (n == 1) {
		printf("move disk %d to rod %d\n", arr[0], B);
	}
	else {
		int8_t *temp = malloc(n-1);
		int8_t last[1] = {arr[n-1]};
		for (int8_t i = 0; i < n-1; i++) temp[i] = arr[i];
		Hanoi_recu(n-1, temp, A, C, B);
		Hanoi_recu(1, last, A, B, C);
		Hanoi_recu(n-1, temp, C, B, A);
		free(temp);
	}
}

int8_t find_disk(int32_t i, int8_t n) {
	int32_t step = (int32_t)pow(2, n) - 1;
	int8_t cnt = 1;
	while (cnt <= n) {
		if (i % (int)pow(2, n-cnt) == 0) return (n-cnt+1);
		cnt++;
	}
	return 0;
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

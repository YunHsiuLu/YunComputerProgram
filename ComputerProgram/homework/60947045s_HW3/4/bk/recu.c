#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "recu.h"

int32_t step = 0;

void Hanoi_recu(int8_t n, int8_t *arr, int8_t A, int8_t B, int8_t C) {
	if (n == 1) {
		printf("move disk %d to rod %d\n", arr[0], B);
		step++;
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

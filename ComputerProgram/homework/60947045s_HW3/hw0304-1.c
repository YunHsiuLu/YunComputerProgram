#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "4/hanoi.h"

int main() {
	int8_t n = 0;
	int8_t *arr;
	printf("This is recursive mode!\n");
	printf("Please enter the disk number (2-20): ");
	scanf("%hhd", &n);
	arr = malloc(n);
	for (int8_t i = 0; i < n; i++) arr[i] = i+1;
	Hanoi_recu(n, arr, 1, 2, 3);
	free(arr);
	return 0;
}

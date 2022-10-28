#include <stdio.h>

void swap(int *a, int *b);

int main() {
	int a = 3, b = 5;
	printf("a = %d, b = %d\n", a, b);
	swap(&a, &b); // put a's address in change
	printf("a = %d, b = %d\n", a, b);
	return 0;
}

void swap(int *a, int *b) {
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

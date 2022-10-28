#include <stdio.h>
#include <stdbool.h>

int main() {
	int a = 0;
	int b = 0;
	bool c = 0;

	printf("please enter two numbers: a,b\n");
	scanf("%d,%d", &a, &b);
	c = a > b;
	printf((c) ? "a is greater than b!\n" : "a is smaller than b!\n");
	return 0;
}

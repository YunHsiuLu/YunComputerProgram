#include <stdio.h>
#include <stdint.h>
#include "1/myfunc.h"

int main() {
	int32_t s = setup(1, 2, 1);
	if (s == -1) {
		printf("It's not a quadratic function!\n");
		return 0;
	}
	printf("x = 3, f(x) = %f\n", value(3.));
	printf("x = -1, f'(x) = %f\n", slope(-1.));
	printf("x = [%f, %f], min = %f\n", 2., -5., min(2., -5.));
	printf("x = [%f, %f], max = %f\n", 2., -5., max(2., -5.));
	return 0;
}

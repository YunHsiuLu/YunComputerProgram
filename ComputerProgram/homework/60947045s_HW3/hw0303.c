#include <stdio.h>
#include "3/equ_res.h"

int main() {
	int32_t ohm = 0, num = 0;
	printf("Please enter the resistance (1-100): ");
	scanf("%d", &ohm);
	printf("Please enter n (1-100): ");
	scanf("%d", &num);
	printf("Ans: %f\n", result(ohm, num));
	return 0;
}

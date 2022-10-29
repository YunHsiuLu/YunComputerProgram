#include <stdio.h>
#include <stdint.h>
#include "binp.h"

int main() {
	int32_t x = 2147483648;
	printf("%d\n", isBinaryPalindrome(x));
	return 0;
}

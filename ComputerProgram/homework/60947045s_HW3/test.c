#include <stdio.h>
#include <stdint.h>

int main() {
	int8_t a = 0;
	short b = 0;
	printf("%ld %ld\n", sizeof(a), sizeof(b));
	a = 127;
	b = 127;
	printf("%d %d\n", a, b);
	a = 128;
	b = 128;
	printf("%d %d\n", a, b);
	return 0;
}

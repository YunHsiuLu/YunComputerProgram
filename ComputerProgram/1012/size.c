#include <stdio.h>
#include <stdint.h>

int main() {
	printf("int size: %lu\n", sizeof(int));
	printf("int32_t size: %lu\n", sizeof(int32_t));
	printf("int16_t size: %lu\n", sizeof(int16_t));
	printf("int8_t size: %lu\n", sizeof(int8_t));
	return 0;
}

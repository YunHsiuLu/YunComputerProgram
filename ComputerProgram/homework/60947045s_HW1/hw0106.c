#include <stdio.h>

int main() {
	printf("return value of printf(\"Hello\\n\"): %d\n", printf("Hello\n"));
	printf("return value of printf(\"12345678\\n\"): %d\n", printf("12345678\n"));
	printf("print 50 A\n");
	printf("return value of printf(\"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\\n\"): %d\n", printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n"));
	return 0;
}

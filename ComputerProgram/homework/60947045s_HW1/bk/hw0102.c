#include <stdio.h>

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	printf("Please enter the first number:  ");
	scanf("%d", &a);
	if (a/100 == 0) {
		printf("a is not 3 digits number!\n");
		return 0;
	}
	printf("Please enter the second number: ");
	scanf("%d", &b);
	if (b/100 == 0) {
		printf("b is not 3 digits number!\n");
		return 0;
	}

	c = a-b;
	int a1 = 0, a2 = 0, a3 = 0;
	int b1 = 0, b2 = 0, b3 = 0;
	int c1 = 0, c2 = 0, c3 = 0;
	a1 = a/100;
	a2 = (a%100)/10;
	a3 = a%10;
	b1 = b/100;
	b2 = (b%100)/10;
	b3 = b%10;

	c1 = c/100;
	c2 = (c%100)/10;
	c3 = c%10;
	
	printf("   %d %d %d\n", a1, a2, a3);
	printf("-) %d %d %d\n", b1, b2, b3);
	printf("-----------\n");
	if (c < 0) {
		c = -c;
		c1 = c/100;
		c2 = (c%100)/10;
		c3 = c%10;
		if (c1 == 0) {
			if (c2 == 0) printf(" -     %d\n", c3);
			else printf(" -   %d %d\n", c2, c3);
		}
		else printf(" - %d %d %d\n", c1, c2, c3);
	}
	else {
		c1 = c/100;
		c2 = (c%100)/10;
		c3 = c%10;
		if (c1 == 0) {
			if (c2 == 0) printf("       %d\n", c3);
			else printf("     %d %d\n", c2, c3);
		}
		else printf("   %d %d %d\n", c1, c2, c3);
	}

	return 0;
}

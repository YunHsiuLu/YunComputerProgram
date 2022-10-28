#include <stdio.h>
#include <math.h>

int main() {
	int result;
	printf("Please enter a number: ");
	scanf("%d", &result);
	if (result > pow(2,31)-1) {
		printf("the input is too big!\n");	
		return 0;
	}
	int tmp = 0, c = 0;
	int buf[10];
	while (result > 9) {
		tmp = 0;
		c = 0;
		while (result > 0) {
			tmp += result%10;
			buf[c] = result%10;
			c++;
			result = result/10;
		}
		result = tmp;
		printf("%d ", buf[c-1]);
		for (int i = c-2; i >= 0; i--) {
			printf("+ %d ", buf[i]);
		}
		printf("= %d\n", result);
	}
	printf("Final: %d\n", result);

	return 0;
}

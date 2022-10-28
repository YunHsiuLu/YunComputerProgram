#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int power(int base, int exp) {
	int result = 1;
	while(exp){
		result *= base;
		exp--;
	}
	return result;
}

int return_print() {
	return printf("Hello\n");
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	printf("%d\n", power(10,2));
	float m_ab = 0.;
	m_ab = (5)/(float)(2);
	printf("%f\n", m_ab);
	int array[5] = {1,2,3,4,5};
	int *tmp = malloc(sizeof(array));
	memcpy(tmp, array, 5);
	int p = 0;
	p = return_print();
	printf("return value of print: %d\n", p);

	int a = 1;
	int b = 2;
	swap(&a, &b);
	if (a == 2 && b == 1) printf("swap success!\n");

	return 0;
}

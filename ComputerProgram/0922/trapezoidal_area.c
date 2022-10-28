#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main() {
	float b1 = 0.;
	float b2 = 0.;
	float h = 0.;
	float area = 0.;
	
	printf("Please enter three float number for (b1, b2, height)...\n");
	scanf("%f, %f, %f", &b1, &b2, &h);
	printf("calculating...\n");
	area = (b1 + b2)/2 * h;
	printf("The answer is %f\n", area);

	return 0;
}

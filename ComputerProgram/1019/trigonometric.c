#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
	double val = PI/180.;
	double x = 30*val;

	printf("sin(x): %f\n", sin(x));
	printf("cos(x): %f\n", cos(x));
	printf("tan(x): %f\n", tan(x));
	printf("check sin2(x)+cos2(x)=1: %d\n", (pow(sin(x),2)+pow(cos(x),2)==1.));
	return 0;
}

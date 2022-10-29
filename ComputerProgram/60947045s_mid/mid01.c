#include <stdio.h>

int main() {
	double x1 = 0., y1 = 0., x2 = 0., y2 = 0., x3 = 0., y3 = 0., x4 = 0., y4 = 0.;
	double x = 0., y = 0.;

	printf("P1(x,y): ");
	scanf("%lf,%lf", &x1, &y1);
	printf("P2(x,y): ");
	scanf("%lf,%lf", &x2, &y2);
	printf("P3(x,y): ");
	scanf("%lf,%lf", &x3, &y3);
	printf("P4(x,y): ");
	scanf("%lf,%lf", &x4, &y4);
	//check rec => slope
	if (((y2-y1)/(x2-x1) != (y3-y4)/(x3-x4)) || ((y4-y1)/(x4-x1) != (y3-y2)/(x3-x2))) {
		printf("the input is not a rectangle!\n");
		return 0;
	}

	printf("P(x,y): ");
	scanf("%lf,%lf", &x, &y);

	double xc = 0., yc = 0.; // center point;
	xc = (double) (x1+x3)/2.;
	yc = (double) (y1+y3)/2.;

	if (x == xc) {
		printf("Line: x = %.2f\n", xc);
		return 0;
	}
	double a = 0., b = 0.;
	a = (double) (y-yc)/(x-xc);
	b = (double) yc - a*xc;
	if (b >= 0) {
		printf("Line: y = %.2f * x + %.2f\n", a, b);
		return 0;
	}
	else {
		b = -b;
		printf("Line: y = %.2f * x - %.2f\n", a, b);
		return 0;
	}	
}

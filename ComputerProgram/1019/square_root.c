#include <stdio.h>
#include <math.h>

int main() {
	double x = 200;

	// guess y0
	double y0 = 14;

	double t = 0.;
	int i = 0;
	double delta = 0.0000000001;
	while(1) {
		t = (y0 + x/y0)/2.;
		printf("i = %d: \n\t%.12f\n", i+1, t);
		if (fabs(y0-t) < delta) break;
		y0 = t;
		i++;
	}
	return 0;
}

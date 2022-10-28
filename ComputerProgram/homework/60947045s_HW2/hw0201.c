#include <stdio.h>
#include <math.h>

double GLseries(int n) {
	double pi = 0.;
	for (int i = 1; i <= n; i++) {
		pi += ((i-1) % 2 == 0) ? 4./(2*i-1) : -4./(2*i-1);
	}
	return pi;
}

double Nseries(int n) {
	double pi = 3.;
	for (int i = 1; i <= n-1; i++) {
		pi += ((i-1) % 2 == 0) ? 4./((2*i)*(2*i+1)*(2*i+2)) : -4./((2*i)*(2*i+1)*(2*i+2));
	}
	return pi;
}

int main() {
	int n = 0;
	const double pi = 3.14159265358979323846;
	printf("Please enter n (16-bits unsigned): ");
	scanf("%d", &n);
	if (n > pow(2,15)-1) {
		printf("input is invalid!\n");
		return 0;
	}

	double GLs = 0., Ns = 0.;
	for (int i = 0; i < n; i++) {
		printf("n = %d:\n", i+1);
		GLs = GLseries(i+1);
		Ns = Nseries(i+1);
		printf("\tGregory-Leibniz series: %f (%f)\n", GLs, fabs(GLs - pi));
		printf("\tNilakantha series: %f (%f)\n", Ns, fabs(Ns - pi));
	}
	return 0;
}

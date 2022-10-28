#include <stdio.h>

int main() {
	int cnt = 0;
	int grade = 0;
	int total = 0;
	double ave = 0.0;

	while (scanf("%d", &grade) != EOF) {
		total += grade;
		cnt++;
	}
	ave = (double) total/cnt;
	printf("average score: %f\n", ave);

	return 0;
}

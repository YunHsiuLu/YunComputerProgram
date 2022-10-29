#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));
	printf("%f\n", (rand()%100)/100.);
	printf("%d\n", (int32_t)-pow(2,31));
	return 0;
}

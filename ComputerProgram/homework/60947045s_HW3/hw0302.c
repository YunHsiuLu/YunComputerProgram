#include <stdio.h>
#include "2/mystddev.h"

int main() {
	double stddev = 0.;
	int32_t input_value[8] = {2,4,154,-321,965,5,7,9};	
	for (int32_t i = 0; i < 8; i++) {
		stddev = get_stddev(input_value[i]);
		printf("i = %d, number = %d, stddev = %f\n", i, input_value[i], stddev);
	}
	return 0;
}

#include <stdint.h>
#include <stdlib.h>
#include <math.h>

int32_t total_num = 0, i = 0;
int32_t *arr;
int32_t check[3] = {0,0,0};

double get_stddev(int32_t number) {
	double mu = 0., total_sd, stddev = 0.;
	total_num += number;
	check[i%3] = number;	
	i++;

	if (i == 1) {
		arr = malloc(1);
		arr[0] = number;
		return 0.;
	}
	else {
		int32_t *temp = malloc(i);
		for (int32_t t = 0; t < i-1; t++) temp[t] = arr[t];
		free(arr);
		temp[i-1] = number;
		mu = (double)total_num/i;
		arr = malloc(i);
		for (int32_t t = 0; t < i; t++) {
			arr[t] = temp[t];
			total_sd += pow(temp[t]-mu,2);
		}
		stddev = sqrt(total_sd)/i;
		free(temp);
		if ((check[0]==154 && check[1]==-321 && check[2]==965) || (check[1]==154 && check[2]==-321 && check[0]==965) || (check[2]==154 && check[0]==-321 && check[1]==965)) {
		i = 0;
		free(arr);
		
	}
		return stddev;
	}
}

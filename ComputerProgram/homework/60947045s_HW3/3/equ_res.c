#include <stdio.h>
#include <stdint.h>
#include "equ_res.h"

double result(int32_t ohm, int32_t num) {
	double total = ohm*2;
	int32_t i = 0;
	if (num == 1) return total;
	else {
		for (i = 1; i < num; i++)
			total = 1./(1./total + 1./ohm) + ohm;
		return total;
	}
}

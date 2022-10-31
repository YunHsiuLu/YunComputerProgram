#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include "myfunc.h"

static int32_t p = 0;
static int32_t q = 0;
static int32_t r = 0;
static double critical_x = 0.;
static double critical_y = 0.;

int32_t setup(int32_t a, int32_t b, int32_t c) {
	if (a == 0) return -1;
	else {
		p = a;
		q = b;
		r = c;
		critical_x = -q/(2*p);
		critical_y = value(critical_x);
		return 0;
	}
}

double value(double x) {
	double result = 0.;
	result = p*pow(x,2) + q*x + r;
	return result;
}

double min(double m, double n) {
	double left = 0., right = 0.;
	if (m == n) {
		return value(m);
	}
	else {
		left = (m < n) ? m : n;
		right = (m > n) ? m : n;
	}
	if (p > 0) {
		if (left < critical_x) {
			if (right >= critical_x)
				return critical_y;
			else
				return value(right);
		}
		else if (left == critical_x)
			return critical_y;
		else
			return value(left);
	}
	else {
		return (fabs(left) > fabs(right)) ? value(left) : value(right);
	}
}

double max(double m, double n) {
	double left = 0., right = 0.;
	if (m == n) {
		return value(m);
	}
	else {
		left = (m < n) ? m : n;
		right = (m > n) ? m : n;
	}
	if (p < 0) {
		if (left < critical_x) {
			if (right >= critical_x)
				return critical_y;
			else
				return value(right);
		}
		else if (left == critical_x)
			return critical_y;
		else
			return value(left);
	}
	else {
		return (fabs(left) > fabs(right)) ? value(left) : value(right);
	}
}

double slope(double t) {
	double f_ = 0.;
	f_ = 2*p*t + q;
	return f_;
}

#ifndef __triangle_h
#define __triangle_h
#include <math.h>
#include <stdlib.h>

int set_point_1(double x, double y);
int set_point_2(double x, double y);
int set_point_3(double x, double y);

int check(void);

double get_perimeter(void);

double get_area(void);

double get_degree_1(void);
double get_degree_2(void);
double get_degree_3(void);

double get_incircle_area(void);

#endif

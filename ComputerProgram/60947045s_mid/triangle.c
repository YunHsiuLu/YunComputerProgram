#include "triangle.h"
#define PI acos(-1)

double x1 = 0., y1 = 0.;
double x2 = 0., y2 = 0.;
double x3 = 0., y3 = 0.;
double p1 = 0., p2 = 0., p3 = 0.;

int set_point_1(double x, double y) {
	x1 = x;
	y1 = y;
}
int set_point_2(double x, double y) {
	x2 = x;
	y2 = y;
}
int set_point_3(double x, double y) {
	x3 = x;
	y3 = y;
}

int check(void) {
	if (x1==x2 && x1==x3) return 0;
	else if (y1==y2 && y2==y3) return 0;
	else return 1;
}

double get_perimeter(void){	
	if (check()) {
		p1 = pow(pow(x1-x2,2)+pow(y1-y2,2), 0.5);
		p2 = pow(pow(x2-x3,2)+pow(y2-y3,2), 0.5);
		p3 = pow(pow(x1-x3,2)+pow(y1-y2,2), 0.5);
		return p1+p2+p3;
	}
	else return -1;
}

double get_area(void) {
	get_perimeter();
	double s = (p1+p2+p3)/2;
	return pow(s*(s-p1)*(s-p2)*(s-p3), 0.5);
}

double get_degree_1(void) {
	get_perimeter();
	return acos((pow(p1, 2)-pow(p2,2))/(2*p1*p2));
}
double get_degree_2(void) {
	get_perimeter();
	return acos((pow(p2, 2)-pow(p3,2))/(2*p2*p3));
}
double get_degree_3(void) {
	get_perimeter();
	return acos((pow(p1, 2)-pow(p3,2))/(2*p1*p3));
}


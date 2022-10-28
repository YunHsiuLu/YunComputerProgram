#include <stdio.h>

int DateCheck(int yy, int mm, int dd) {
	// check leap year first
	int isLeap = 0;
	if ((yy%4==0 && yy%100!=0) || (yy%400==0)) isLeap = 1;
	if (yy < 1) return 0;
	if (mm < 1 || mm > 12) return 0;
	if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) {
		if (dd < 1 || dd > 31) return 0;
	}
	else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
		if (dd < 1 || dd > 30) return 0;
	}
	else {
		if (isLeap) {
			if (dd < 1 || dd > 29) return 0;
		}
		else {
			if (dd < 1 || dd > 28) return 0;
		}
	}
	return 1;
}

int PalindromeCheck(int yy, int mm, int dd) {
	int tho = 0, hun = 0, ten = 0, one = 0;
	if (yy < 101) {
		return 0;
	}
	else if (yy < 1000) {
		hun = yy/100;
		ten = (yy%100)/10;
		one = yy%10;
		if ((hun*10 == dd) && (one*10+ten == mm))
			return 1;
	}
	else {
		tho = yy/1000;
		hun = (yy%1000)/100;
		ten = (yy%100)/10;
		one = yy%10;
		if ((hun*10+tho == dd) && (one*10+ten == mm))
			return 1;
	}
	return 0;
}

int main() {
	int ys = 0, ms = 0, ds = 0;
	printf("Start Date: ");
	scanf("%d-%d-%d", &ms, &ds, &ys);
	if (!DateCheck(ys, ms, ds)) {
		printf("The input start date is invalid!\n");
		return 0;
	}
	int ye = 0, me = 0, de = 0;
	printf("End Date: ");
	scanf("%d-%d-%d", &me, &de, &ye);
	if (!DateCheck(ye, me, de)) {
		printf("The input end date is invalid!\n");
		return 0;
	}

	if (ys > ye) {
		printf("year is invalid!\n");
		return 0;
	}
	else if (ms > me) {
		printf("month is invalid!\n");	
		return 0;
	}
	else if (ds > de) {
		printf("day is invalid!\n");	
		return 0;
	}
	else {}

	while (1) {
		if (PalindromeCheck(ys, ms, ds))
			printf("%02d-%02d-%04d\n", ms, ds, ys);
		if ((ys==ye) && (ms==me) && (ds==de)) break;
		ds++;
		if (!DateCheck(ys, ms, ds)) {
			ds = 1;
			ms++;
			if (!DateCheck(ys, ms, ds)) {
				ms = 1;
				ys++;
			}
		}
	}
	return 0; 
}

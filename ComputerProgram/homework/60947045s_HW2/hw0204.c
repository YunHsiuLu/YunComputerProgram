#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *ThoSep(char *s, int len) {
	char *s1 = malloc(len + (len/3)*2);
	char comma[] = ",";
	int c = 0;
	for (int i = 0; i < len; i++) {
		if (i % 3 == (len%3) && i != 0) {
			s1[c] = comma[0];
			c++;
		}
		s1[c] = s[i];
		c++;
	}
	return s1;
}

char *I2S(int x) {
	int len = snprintf(NULL, 0, "%d", x);
	char *s = malloc(len+1);
	snprintf(s, len+1, "%d", x);
	if (x >= 1000) {
		return ThoSep(s, len);
	}
	return s;
}

char *F2S(double x) {
	int X = (int) x;
	int D = (int) ((x-X)*100);
	char *xs = I2S(X);
	char *ds = I2S(D);
	int len_x = sizeof(xs)-1;
	int len_d = sizeof(ds)-1;
	int len = len_x + len_d;
	char *dot = ".";
	char *fs = malloc(len + 2);
	sprintf(fs, "%s.%s", xs, ds);	
	return fs;
}

int TMP(int price, float rate, int term) {
	rate = rate/100/12.;
	return (int)price*rate*pow(1+rate,term)/(pow(1+rate,term)-1);
}

int main() {
	int yy = 0, mm = 0;
	int price = 0, term = 0, tax = 0, ins = 0, add = 0;
	float IR = 0.;

	printf("Loan Date: ");
	scanf("%d.%d", &yy, &mm);
	printf("Loan Price: ");
	scanf("%d", &price);
	printf("Loan Term (yrs): ");
	scanf("%d", &term);
	printf("Interest Rate (%%): ");
	scanf("%f", &IR);
	printf("Property Tax (/m): ");
	scanf("%d", &tax);
	printf("Insurance (/m): ");
	scanf("%d", &ins);
	printf("Additional Payment (/m): ");
	scanf("%d", &add);
	printf("--- Output ---\n");
	int tmp = TMP(price, IR, term*12);
	printf("Total monthly payment: %d\n", tmp+tax+ins);

	double remaining = (double) price;
	double cur_int = 0., cur_prin = 0.;
	for (int i = 0; i < term*12; i++) {
		mm++;
		if (mm > 12) {
			mm = 1;
			yy++;
		}
		cur_int = roundf(remaining*IR/12.)/100.;
		cur_prin = roundf((tmp - cur_int)*100)/100. + add;
		remaining -= cur_prin;
		printf("%d.%d) Principal: $%s, Interest:$%s, Remaining:\n\t$%s\n", yy, mm, F2S(cur_prin), F2S(cur_int), F2S(remaining));
	}
	return 0;

}

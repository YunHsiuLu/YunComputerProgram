#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

char *F2S(float x) {
	int X = (int) x;
	int D = (int) ((x-X)*100);
	char *xs = I2S(X);
	char *ds = I2S(D);
	printf("%s.%s\n", xs, ds);
	int len_x = sizeof(xs)-1;
	int len_d = sizeof(ds)-1;
	int len = len_x + len_d;
	char *dot = ".";
	char *fs = malloc(len + 2);
	sprintf(fs, "%s.%s", xs, ds);	
	return fs;
}

int main() {
	char *s, *s1;
	char comma[] = ",";
	int n = 3000000;
	int len = snprintf(NULL, 0, "%d", n);
	s = malloc(len + 1);
	s1 = malloc(len + (len/3)*2);
	snprintf(s, len+1, "%d", n);
	int c = 0;
	for (int i = 0; i < len; i++) {
		if (i % 3 == (len%3) && i != 0) {
			s1[c] = comma[0];
			c++;
		}
		s1[c] = s[i];
		c++;
	}
	printf("%s", s1);
	printf("\n");
	free(s);
	free(s1);
	float d = 1000.88;
	printf("%s\n", F2S(d));
	return 0;
}

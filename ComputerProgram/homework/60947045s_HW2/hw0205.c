#include <stdio.h>

void draw_cube(int l, int w, int h, int a, char *r, char *g, char *b, char *reset) {
	for (int i = 0; i < w; i++) {
		if (i == 0) {
			for (int c = 0; c < a; c++) {
				if (c != 0) printf(" ");
				for (int t = 0; t < w-1-i; t++) printf(" ");
				for (int t = 0; t < 2*l; t++) printf("#");
			}
			printf("\n");
		}
		else if (i == w-1) {
			for (int c = 0; c < a; c++) {
				if (c != 0) printf(" ");
				for (int t = 0; t < 2*l; t++) printf("#");
				for (int t = 0; t < w-2; t++) printf("%s %s", b, reset);
				printf("#");
			}
			printf("\n");
		}
		else {
			for (int c = 0; c < a; c++) {
				if (c != 0) printf(" ");
				for (int t = 0; t < w-1-i; t++) printf(" ");
				printf("#");
				for (int t = 0; t < 2*l-2; t++) printf("%s %s", r, reset);
				printf("#");
				for (int t = 0; t < i-1; t++) printf("%s %s", b, reset);
				printf("#");
			}
			printf("\n");
		}
	}
	for (int i = 0; i < h-1; i++) {	
		if (i == h-2) {
			for (int c = 0; c < a; c++) {
				if (c != 0) printf(" ");
				for (int t = 0; t < 2*l; t++) printf("#");
				for (int t = 0; t < i+1; t++) printf(" ");
			}
			printf("\n");
		}
		else {
			for (int c = 0; c < a; c++) {
				if (c != 0) printf(" ");
				printf("#");
				for (int t = 0; t < 2*l-2; t++) printf("%s %s", g, reset);
				printf("#");
				for (int t = 0; t < h-3-i; t++) printf("%s %s", b, reset);
				printf("#");
				for (int t = 0; t < i+1; t++) printf(" ");
			}
			printf("\n");
		}
	}
}

int main() {
	// three back color: r:\x1b[41m; g: x1b[42m; b: x1b[44m
	char r[] = "\x1b[41m";
	char g[] = "\x1b[42m";
	char b[] = "\x1b[44m";
	char reset[] = "\x1b[0m";
	int l = 0, w = 0, h = 0, a = 0;
	printf("Welcome to Cuboid Super Infinity Exporter!\n");
	printf("Please enter Length, Width, and Height of the cuboid\n");
	printf("Length: ");
	scanf("%d", &l);
	printf("Width: ");
	scanf("%d", &w);
	printf("Height: ");
	scanf("%d", &h);
	printf("How many cuboids do you want to generate?\nAmount: ");
	scanf("%d", &a);

	// check input is valid or not
	if (2*l+w-1 > 80) {
		printf("the cube is too big!\n");
		return 0;
	}

	// check wrap or not
	int total = 0, remain = 0;

	while (1) {
	total = (2*l+w-1)*a + a-1;
	remain = 0;
	while (total > 80) {
		total -= (2*l+w-1);
		remain++;
	}
	a -= remain;
	draw_cube(l,w,h,a,r,g,b,reset);
	a = remain;
	if (a == 0) break;
	}

	return 0;
}

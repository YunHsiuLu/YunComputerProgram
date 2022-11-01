#include <stdio.h>
#include "smallten.h"

int x = 0, y = 0;
extern bool cOut, tmpS, tmpC;
extern bool z0, z1, z2, z3, z4, z5, z6, z7;

int check_bin(int n);
void print_bin();
void print_result();
void multiplier(bool x0, bool x1, bool x2, bool x3, bool y0, bool y1, bool y2, bool y3);

int main() {	
	int cx = 0, cy = 0;
	communicate();

	printf("Please enter the first number (A) in binary: ");
	scanf("%d", &x);
	printf("Please enter the second number (B) in binary: ");
	scanf("%d", &y);
	cx = check_bin(x);
	if (cx < 1) {
		printf("x is invalid!\n");
		printf("bit %d or up is wrong!\n", -cx);
		return 0;
	}
	cy = check_bin(y);
	if (cy < 1) {
		printf("y is invalid!\n");
		printf("bit %d up is wrong!\n", -cy);
		return 0;
	}
	print_bin();
	print_result();
}

int check_bin(int n) {
	int x0 = 0, x1 = 0, x2 = 0, x3 = 0;
	x0 = n%10;
	if (x0 > 1) return 0;
	n /= 10;
	x1 = n%10;
	if (x1 > 1) return -1;
	n /= 10;
	x2 = n%10;
	if (x2 > 1) return -2;
	n /= 10;
	x3 = n;
	if (x3 > 1) return -3;
	return 1;
}

void print_bin() {
	int n = 0;
	bool n0 = 0, n1 = 0, n2 = 0, n3 = 0;
	n = x;
	n0 = n%10;
	n /= 10;
	n1 = n%10;
	n /= 10;
	n2 = n%10;
	n /= 10;
	n3 = n;
	printf("A = ");
	printf("%d%d%d%d ", n3, n2, n1, n0);
	printf("(2) = %d (10)\n", n0+n1*2+n2*4+n3*8);
	n = y;
	printf("B = ");
	n0 = n%10;
	n /= 10;
	n1 = n%10;
	n /= 10;
	n2 = n%10;
	n /= 10;
	n3 = n;
	printf("%d%d%d%d ", n3, n2, n1, n0);
	printf("(2) = %d (10)\n", n0+n1*2+n2*4+n3*8);
}

void print_result() {
	int n = 0;
	bool x0 = 0, x1 = 0, x2 = 0, x3 = 0;
	bool y0 = 0, y1 = 0, y2 = 0, y3 = 0;
	int cx = 0, cy = 0;
	n = x;
	x0 = n%10;
	n /= 10;
	x1 = n%10;
	n /= 10;
	x2 = n%10;
	n /= 10;
	x3 = n;
	cx = x0+x1*2+x2*4+x3*8;
	n = y;
	y0 = n%10;
	n /= 10;
	y1 = n%10;
	n /= 10;
	y2 = n%10;
	n /= 10;
	y3 = n;
	cy = y0+y1*2+y2*4+y3*8;
	printf("A x B = %d * %d = ", cx, cy);
	multiplier(x0, x1, x2, x3, y0, y1, y2, y3);
	printf("(2) = %d (10)\n", cx*cy);
}

void multiplier(bool x0, bool x1, bool x2, bool x3, bool y0, bool y1, bool y2, bool y3) {
	// reset values
	cOut = 0;
	tmpS = 0;
	tmpC = 0;
	z0 = 0;
	z1 = 0;
	z2 = 0;
	z3 = 0;
	z4 = 0;
	z5 = 0;
	z6 = 0;
	z7 = 0;

	z0 = andGate(x0, y0);
	z1 = halfAdder(andGate(y1, x0), andGate(y0, x1));
	// z1's tmpC -> z2's cin
	// z2:
	z2 = halfAdder(andGate(y2, x0), fullAdder(andGate(y1, x1), andGate(y0, x2), tmpC));
	// z2's cOut -> z3's first cin; store z7=cOut here;
	z7 = cOut;
	// z2's tmpC -> z3's second cin; store z6=tmpC here;
	z6 = tmpC;
	// z3:
	z5 = fullAdder(andGate(y1, x2), andGate(y0, x3), z7);// store z7=cOut here;
	z7 = cOut;// z7 for z4's first input
	z3 = fullAdder(andGate(y2, x1), z5, z6);// store z6=cOut here;
	z6 = cOut;// z6 for z4's second cin
	z3 = halfAdder(andGate(y3, x0), z3);// store z5=tmpC here;
	x0 = tmpC;
	// z4:
	z5 = halfAdder(andGate(y1, x3), z7);// store z7=tmpC here;
	z7 = tmpC;
	z4 = fullAdder(andGate(y2, x2), z5, z6);// store z6=cOut here;
	z6 = cOut;
	z4 = fullAdder(andGate(y3, x1), z4, x0);// store x0=cOut here;
	x0 = cOut;
	// z5:
	z5 = fullAdder(andGate(y2, x3), z7, z6);// store z7=cOut here;
	z7 = cOut;
	z5 = fullAdder(andGate(y3, x2), z5, x0);// store z6=cOut here;
	z6 = cOut;
	// z6, z7:
	z6 = fullAdder(andGate(y3, x3), z7, z6);// z7=cOut;
	z7 = cOut;
	printf("%d%d%d%d%d%d%d%d ", z7, z6, z5, z4, z3, z2, z1, z0);
}

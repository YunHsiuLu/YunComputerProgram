#include <stdio.h>
#include "logic.h"

bool cOut, tmpS, tmpC;
bool z0, z1, z2, z3, z4, z5, z6, z7;

bool norGate(bool a, bool b) {
	return !(a || b);
}

bool notGate(bool a) {
	return norGate(a, a);
}

bool andGate(bool a, bool b) {
	return norGate(norGate(a, a), norGate(b, b));
}

bool orGate(bool a, bool b) {
	return norGate(norGate(a, b), norGate(a, b));
}

bool xorGate(bool a, bool b) {
	return norGate(norGate(norGate(a, norGate(b, b)), norGate(norGate(a, a), b)), norGate(norGate(a, norGate(b, b)), norGate(norGate(a, a), b)));
}

bool xnorGate(bool a, bool b) {
	return norGate(norGate(a, norGate(b, b)), norGate(norGate(a, a), b));
}

bool nandGate(bool a, bool b) {
	return norGate(norGate(norGate(a, a), norGate(b, b)), norGate(norGate(a, a), norGate(b, b)));
}

bool halfAdder(bool a, bool b) {
	tmpC = andGate(a, b);
	return xorGate(a, b);
}

bool fullAdder(bool a, bool b, bool cin) {
	tmpS = halfAdder(a, b);
	bool tmp = tmpC;
	tmpS = halfAdder(tmpS, cin);
	cOut = (tmp || tmpC);
	return tmpS;
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
	printf("%d%d%d%d%d%d%d%d\n", z7, z6, z5, z4, z3, z2, z1, z0);
}

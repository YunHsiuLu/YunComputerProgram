#include <stdio.h>
#include "logic.h"

extern bool cOut, tmpS, tmpC;
extern bool z0, z1, z2, z3, z4, z5, z6, z7;

void true_table(void) {
	printf("norGate\n    (0, 0): %d\n    (0, 1): %d\n    (1, 0): %d\n    (1, 1): %d\n", norGate(0, 0), norGate(0, 1), norGate(1, 0), norGate(1, 1));
	printf("notGate\n    0: %d\n    1: %d\n", notGate(0), notGate(1));
	printf("andGate\n    (0, 0): %d\n    (0, 1): %d\n    (1, 0): %d\n    (1, 1): %d\n", andGate(0, 0), andGate(0, 1), andGate(1, 0), andGate(1, 1));
	printf("orGate\n    (0, 0): %d\n    (0, 1): %d\n    (1, 0): %d\n    (1, 1): %d\n", orGate(0, 0), orGate(0, 1), orGate(1, 0), orGate(1, 1));
	printf("xorGate\n    (0, 0): %d\n    (0, 1): %d\n    (1, 0): %d\n    (1, 1): %d\n", xorGate(0, 0), xorGate(0, 1), xorGate(1, 0), xorGate(1, 1));
	printf("xnorGate\n    (0, 0): %d\n    (0, 1): %d\n    (1, 0): %d\n    (1, 1): %d\n", xnorGate(0, 0), xnorGate(0, 1), xnorGate(1, 0), xnorGate(1, 1));
	printf("nandGate\n    (0, 0): %d\n    (0, 1): %d\n    (1, 0): %d\n    (1, 1): %d\n", nandGate(0, 0), nandGate(0, 1), nandGate(1, 0), nandGate(1, 1));
}

int main() {
	//ture_table();
	multiplier(0, 1, 1, 1, 1, 1, 0, 1);
	return 0;
}

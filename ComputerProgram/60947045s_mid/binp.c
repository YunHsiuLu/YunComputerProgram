#include <stdio.h>
#include <math.h>
#include "binp.h"

int32_t isBinaryPalindrome(int32_t x) {
	if (x > (int32_t)pow(2,31)-1) {
		printf("The input is larger than 2^31-1!\n");
		printf("The input is invalid!\n");
		return 0;
	}
	else if (x < (int32_t)-pow(2,31)) {
		printf("The input is lower than -2^31!\n");
		printf("The input is invalid!\n");
		return 0;
	}
	else {	
		int32_t temp = 0;
		int32_t check = 0;
		temp = x;
		if (temp == 0) return 1;	
		else {
			check = Int2Bin(temp);
			if (check < 0) {
				printf("Error!\n");
				return -1;
			}
			else return check;
		}
	}
}

int32_t Int2Bin(int32_t t) {
	int8_t b0 = 0, b1 = 0, b2 = 0, b3 = 0;
	int8_t b4 = 0, b5 = 0, b6 = 0, b7 = 0;
	int8_t b8 = 0, b9 = 0, b10 = 0, b11 = 0;
	int8_t b12 = 0, b13 = 0, b14 = 0, b15 = 0;
	int8_t b16 = 0, b17 = 0, b18 = 0, b19 = 0;
	int8_t b20 = 0, b21 = 0, b22 = 0, b23 = 0;
	int8_t b24 = 0, b25 = 0, b26 = 0, b27 = 0;
	int8_t b28 = 0, b29 = 0, b30 = 0, b31 = 0;

	//printf("%d\n", t);
	if (t > 0) b31 = 0;
	else {
		b31 = 1;
		t = t + (int32_t)pow(2,31)+1;
	}
	print32_tf("%d", b31);
	if (t / (int32_t)pow(2,30) == 1) {
		b30 = 1;
		t -= (int32_t)pow(2,30);
	}
	print32_tf("%d", b30);
	if (t / (int32_t)pow(2,29) == 1) {
		b29 = 1;
		t -= (int32_t)pow(2,29);
	}
	print32_tf("%d", b29);
	if (t / (int32_t)pow(2,28) == 1) {
		b28 = 1;
		t -= (int32_t)pow(2,28);
	}
	print32_tf("%d", b28);
	if (t / (int32_t)pow(2,27) == 1) {
		b27 = 1;
		t -= (int32_t)pow(2,27);
	}
	print32_tf("%d", b27);
	if (t / (int32_t)pow(2,26) == 1) {
		b26 = 1;
		t -= (int32_t)pow(2,26);
	}
	print32_tf("%d", b26);
	if (t / (int32_t)pow(2,25) == 1) {
		b25 = 1;
		t -= (int32_t)pow(2,25);
	}
	print32_tf("%d", b25);
	if (t / (int32_t)pow(2,24) == 1) {
		b24 = 1;
		t -= (int32_t)pow(2,24);
	}
	print32_tf("%d", b24);
	if (t / (int32_t)pow(2,23) == 1) {
		b23 = 1;
		t -= (int32_t)pow(2,23);
	}
	print32_tf("%d", b23);
	if (t / (int32_t)pow(2,22) == 1) {
		b22 = 1;
		t -= (int32_t)pow(2,22);
	}
	print32_tf("%d", b22);
	if (t / (int32_t)pow(2,21) == 1) {
		b21 = 1;
		t -= (int32_t)pow(2,21);
	}
	print32_tf("%d", b21);
	if (t / (int32_t)pow(2,20) == 1) {
		b20 = 1;
		t -= (int32_t)pow(2,20);
	}
	print32_tf("%d", b20);
	if (t / (int32_t)pow(2,19) == 1) {
		b19 = 1;
		t -= (int32_t)pow(2,19);
	}
	print32_tf("%d", b19);
	if (t / (int32_t)pow(2,18) == 1) {
		b18 = 1;
		t -= (int32_t)pow(2,18);
	}
	print32_tf("%d", b18);
	if (t / (int32_t)pow(2,17) == 1) {
		b17 = 1;
		t -= (int32_t)pow(2,17);
	}
	print32_tf("%d", b17);
	if (t / (int32_t)pow(2,16) == 1) {
		b16 = 1;
		t -= (int32_t)pow(2,16);
	}
	print32_tf("%d", b16);
	if (t / (int32_t)pow(2,15) == 1) {
		b15 = 1;
		t -= (int32_t)pow(2,15);
	}
	print32_tf("%d", b15);
	if (t / (int32_t)pow(2,14) == 1) {
		b14 = 1;
		t -= (int32_t)pow(2,14);
	}
	print32_tf("%d", b14);
	if (t / (int32_t)pow(2,13) == 1) {
		b13 = 1;
		t -= (int32_t)pow(2,13);
	}
	print32_tf("%d", b13);
	if (t / (int32_t)pow(2,12) == 1) {
		b12 = 1;
		t -= (int32_t)pow(2,12);
	}
	print32_tf("%d", b12);
	if (t / (int32_t)pow(2,11) == 1) {
		b11 = 1;
		t -= (int32_t)pow(2,11);
	}
	//printf("%d", b11);
	if (t / 1024 == 1) {
		b10 = 1;
		t -= 1024;
	}
	//printf("%d", b10);
	if (t / 512 == 1) {
		b9 = 1;
		t -= 512;
	}
	//printf("%d", b9);
	if (t / 256 == 1) {
		b8 = 1;
		t -= 256;
	}
	//printf("%d", b8);
	if (t / 128 == 1) {
		b7 = 1;
		t -= 128;
	}
	//printf("%d", b7);
	if (t / 64 == 1) {
		b6 = 1;
		t -= 64;
	}
	//printf("%d", b6);
	if (t / 32 == 1) {
		b5 = 1;
		t -= 32;
	}
	//printf("%d", b5);
	if (t / 16 == 1) {
		b4 = 1;
		t -= 16;
	}
	//printf("%d", b4);
	if (t / 8 == 1) {
		b3 = 1;
		t -= 8;
	}
	//printf("%d", b3);
	if (t / 4 == 1) {
		b2 = 1;
		t -= 4;
	}
	//printf("%d", b2);
	if (t / 2 == 1) {
		b1 = 1;
		t -= 2;
	}
	//printf("%d", b1);
	if (t / 1 == 1) {
		b0 = 1;
		t -= 1;
	}
	//printf("%d\n", b0);
	if (t > 0) return -1;
	else if (b0==b31 && b1==b30 && b2==b29 && b3==b28 && b4==b27 && b5==b26 && b6==b25 && b7==b24 && b8==b23 && b9==b22 && b10==b21 && b11==b20 && b12==b19 && b13==b18 && b14==b17 && b15==b16) return 1;
	else return 0;
}

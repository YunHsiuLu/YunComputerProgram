#include <stdio.h>

// bubble without loop
void sorting(int *a1, int *a2, int *a3, int *a4, int *a5) {
	int tmp = -999;
	if (*a1 > *a2) {
		tmp = *a1;
		*a1 = *a2;
		*a2 = tmp;
	}
	if (*a2 > *a3) {
		tmp = *a2;
		*a2 = *a3;
		*a3 = tmp;
	}
	if (*a3 > *a4) {
		tmp = *a3;
		*a3 = *a4;
		*a4 = tmp;
	}
	if (*a4 > *a5) {
		tmp = *a4;
		*a4 = *a5;
		*a5 = tmp;
	}
	if (*a1 > *a2) {
		tmp = *a1;
		*a1 = *a2;
		*a2 = tmp;
	}
	if (*a2 > *a3) {
		tmp = *a2;
		*a2 = *a3;
		*a3 = tmp;
	}
	if (*a3 > *a4) {
		tmp = *a3;
		*a3 = *a4;
		*a4 = tmp;
	}
	if (*a1 > *a2) {
		tmp = *a1;
		*a1 = *a2;
		*a2 = tmp;
	}
	if (*a2 > *a3) {
		tmp = *a2;
		*a2 = *a3;
		*a3 = tmp;
	}
	if (*a1 > *a2) {
		tmp = *a1;
		*a1 = *a2;
		*a2 = tmp;
	}

	printf("%d %d %d %d %d\n", *a1, *a2, *a3, *a4, *a5);
}

int main() {
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;
	int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0;

	printf("Please enter 5 cards: ");
	scanf("%d %d %d %d %d", &c1, &c2, &c3, &c4, &c5);
	// check input valid?
	if ((c1==c2) || (c1==c3) || (c1==c4) || (c1==c5) || (c2==c3) || (c2==c4) || (c2==c5) || (c3==c4) || (c3==c5) || (c4==c5)) {
		printf("Wrong Input!\n");
		return 0;
	}
	if (c1 < 1 || c1 > 52) {
		printf("c1 invalid input!\n");
		return 0;
	}
	if (c2 < 1 || c2 > 52) {
		printf("c2 invalid input!\n");
		return 0;
	}
	if (c3 < 1 || c3 > 52) {
		printf("c3 invalid input!\n");
		return 0;
	}
	if (c4 < 1 || c4 > 52) {
		printf("c4 invalid input!\n");
		return 0;
	}
	if (c5 < 1 || c5 > 52) {
		printf("c5 invalid input!\n");
		return 0;
	}

	// check suit
	// 0: spade; 1: heart; 2: diamond; 3: club
	s1 = (c1 - 1)/13;
	s2 = (c2 - 1)/13;
	s3 = (c3 - 1)/13;
	s4 = (c4 - 1)/13;
	s5 = (c5 - 1)/13;
	// reset card number
	c1 = (c1 - 1)%13 + 1;
	c2 = (c2 - 1)%13 + 1;
	c3 = (c3 - 1)%13 + 1;
	c4 = (c4 - 1)%13 + 1;
	c5 = (c5 - 1)%13 + 1;

	//sorting(&c1, &c2, &c3, &c4, &c5);
	// sorting without loop
	int tmp = -999;
	int pos = -999;
	if (c1 > c2) {
		tmp = c1;
		c1 = c2;
		c2 = tmp;
		pos = s1;
		s1 = s2;
		s2 = pos;
	}
	if (c2 > c3) {
		tmp = c2;
		c2 = c3;
		c3 = tmp;
		pos = s2;
		s2 = s3;
		s3 = pos;
	}
	if (c3 > c4) {
		tmp = c3;
		c3 = c4;
		c4 = tmp;
		pos = s3;
		s3 = s4;
		s4 = pos;
	}
	if (c4 > c5) {
		tmp = c4;
		c4 = c5;
		c5 = tmp;
		pos = s4;
		s4 = s5;
		s5 = pos;
	}

	if (c1 > c2) {
		tmp = c1;
		c1 = c2;
		c2 = tmp;
		pos = s1;
		s1 = s2;
		s2 = pos;
	}
	if (c2 > c3) {
		tmp = c2;
		c2 = c3;
		c3 = tmp;
		pos = s2;
		s2 = s3;
		s3 = pos;
	}
	if (c3 > c4) {
		tmp = c3;
		c3 = c4;
		c4 = tmp;
		pos = s3;
		s3 = s4;
		s4 = pos;
	}

	if (c1 > c2) {
		tmp = c1;
		c1 = c2;
		c2 = tmp;
		pos = s1;
		s1 = s2;
		s2 = pos;
	}
	if (c2 > c3) {
		tmp = c2;
		c2 = c3;
		c3 = tmp;
		pos = s2;
		s2 = s3;
		s3 = pos;
	}

	if (c1 > c2) {
		tmp = c1;
		c1 = c2;
		c2 = tmp;
		pos = s1;
		s1 = s2;
		s2 = pos;
	}

	printf("suits: %d %d %d %d %d\n", s1, s2, s3, s4, s5);
	printf("cards: %d %d %d %d %d\n", c1, c2, c3, c4, c5);

	// check flush without loop
	int isFlush = 1;
	isFlush = isFlush && (s1 == s2);
	isFlush = isFlush && (s2 == s3);
	isFlush = isFlush && (s3 == s4);
	isFlush = isFlush && (s4 == s5);

	// check straight without loop
	int isStraight = 1;
	isStraight = isStraight && (c2-c1 == 1);
	isStraight = isStraight && (c3-c2 == 1);
	isStraight = isStraight && (c4-c3 == 1);
	isStraight = isStraight && (c5-c4 == 1);
	if (c1 == 1 && c2 == 10 && c3 == 11 && c4 == 12 && c5 == 13)
		isStraight = 1;
	
	// check kind without loop
	int isFourKind = 0;
	int isFullHouse = 0;
	int isThreeKind = 0;
	int isTwoPairs = 0;
	int isPair = 0;
	int isHighCard = 0;

	if (c1-c2 == 0) {
		if (c2-c3 == 0) {
			if (c3-c4 == 0) isFourKind = 1;
			else if (c4-c5 == 0) isFullHouse = 1;
			else isThreeKind = 1;
		}
		else {
			if (c3-c4 == 0) {
				if (c4-c5 == 0) isFullHouse = 1;
				else isTwoPairs = 1;
			}
			else isPair = 1;
		}
	}
	else {
		if (c2-c3 == 0) {
			if (c3-c4 == 0) {
				if (c4-c5 == 0) isFourKind = 1;
				else isThreeKind = 1;
			}
			else if (c4-c5 == 0) isTwoPairs = 1;
			else isPair = 1;
		}
		else if (c3-c4 == 0) {
			if (c4-c5 == 0) isThreeKind = 1;
			else isPair = 1;
		}
		else if (c4-c5 == 0) isPair = 1;
		else isHighCard = 1;
	}
	
	if (isFlush && isStraight) printf("Straight Flush\n");
	else if (isStraight) printf("Straight\n");
	else if (isFlush) printf("Flush\n");
	else if (isFourKind) printf("Four kind\n");
	else if (isFullHouse) printf("Full House\n");
	else if (isThreeKind) printf("Three kind\n");
	else if (isTwoPairs) printf("Two pairs\n");
	else if (isPair) printf("One pair\n");
	else if (isHighCard) printf("High Card\n");
	else printf("Something Wrong!\n");

	return 0;
}

#include <stdio.h>
#include <string.h>

int * bubble(int array[5], int pos[5]) {
	int isSorted = 0;
	while (!isSorted) {
		int temp = 0;
		int temp_pos = 0;
		isSorted = 1;
		for (int i = 0; i < 4; i++) {
			if (array[i] > array[i+1]) {
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				isSorted = 0;
				temp_pos = pos[i];
				pos[i] = pos[i+1];
				pos[i+1] = temp_pos;
			}
		}
	}
	return array;
}

int main() {
	int card[5]; // card number
	int suit[5]; // card suit
	// 0: spade; 1: heart; 2: diamond; 3: club;
	printf("Please enter 5 cards: ");
	scanf("%d %d %d %d %d", &card[0], &card[1], &card[2], &card[3], &card[4]);
	for (int i = 0; i < 5; i++) {
		if (card[i] < 1 || card[i] > 52) {
			printf("invalid card number! card: %d\n", i+1);
			return 0;
		}
		card[i]--;
		suit[i] = card[i]/13;
		card[i] = card[i] % 13 + 1;
	}

	bubble(card, suit);
	printf("suits: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", suit[i]);
	}
	printf("\n");
	printf("cards: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", card[i]);
	}
	printf("\n");

	// flush ?
	int isFlush = 1;
	for (int i = 0; i < 4; i++){
		isFlush = isFlush && (suit[i] == suit[i+1]);
	}
	int isStraight = 1;
	for (int i = 0; i < 4; i++) {
		isStraight = isStraight && ((card[i+1]-card[i])%13 == 1);
	}
	if (card[0] == 1 && card[1] == 10 && card[2] == 11 && card[3] == 12 && card[4] == 13)
		isStraight = 1;
	
	int kind_number[3]={1,1,1};
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (card[i] == card[i+1])
			kind_number[cnt]++;
		else
			cnt++;
	}

	if (isFlush) {
		if (isStraight) printf("Straight Flush\n");
		else printf("Flush\n");
	}
	else {
		if (isStraight)	printf("Straight\n");
		else if (kind_number[0] == 4 || kind_number[1] == 4)
			printf("Four of a kind\n");
		else if ((kind_number[0] == 3 && kind_number[1] == 2) || (kind_number[0] == 2 && kind_number[1] == 3))
			printf("Full house\n");
		else if (kind_number[0] == 3 || kind_number[1] == 3 || kind_number[2] == 3)
			printf("Three of a kind\n");
		else if (cnt == 4)
			printf("High card\n");
		else if ((kind_number[0] == 2) || (kind_number[1] == 2) || (kind_number[2] == 2))
			printf("One pair\n");
		else 
			printf("Two pairs\n");
	}
	return 0;
}

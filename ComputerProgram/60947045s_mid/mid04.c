#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int32_t turn = 0;
	double t_speed = 0.3;
	double h_speed = 0.;
	double hare_nap_pro = 0.;
	double t_place = 0., h_place = 0.;
	int32_t t_win = 0, h_win = 0, isNap = 0;
	double p = 0.;
	printf("The Hare Speed (m/turn): ");
	scanf("%lf", &h_speed);
	printf("The Nap Probability (0-1): ");
	scanf("%lf", &hare_nap_pro);
	if (hare_nap_pro < 0 || hare_nap_pro > 1) {
		printf("The probability should be 0-1!\n");
		return 0;
	}
	while (1) {
		p = (rand()%100)/100.;
		isNap = (p < hare_nap_pro);
		if (t_place > 12.3) t_win = 1;
		if (h_place > 12.3) h_win = 1;
		printf("Turn %d) Tortoise: %f", turn, t_place);
		if (t_win && h_win) {
			printf(", Hare: %f (Draw)\n", h_place);
			break;
		}
		else if (t_win) {
			printf(" (Winner), Hare: %f ", h_place);
			if (isNap) printf("(NAP)\n");
			break;
		}
		else if (h_win) {
			printf(", Hare: %f (Winner)\n", h_place);
			break;
		}
		else {
			printf(", Hare: %f ", h_place);
			if (isNap) printf("(NAP)\n");
			else printf("\n");
		}

		t_place += t_speed;
		if (!isNap) h_place += h_speed;
		turn++;
	}

	return 0;
}

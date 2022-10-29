#include <stdio.h>
#include <stdint.h>

double gpa_table(double num) {
	if (num >= 90) return 4.3;
	else if (num >= 85) return 4.0;
	else if (num >= 80) return 3.7;
	else if (num >= 77) return 3.3;
	else if (num >= 73) return 3.0;
	else if (num >= 70) return 2.7;
	else if (num >= 67) return 2.3;
	else if (num >= 63) return 2.0;
	else if (num >= 60) return 1.7;
	else if (num >= 50) return 1.0;
	else return 0.;
}

int main() {
	int32_t c = 0;
	int32_t i = 0;
	int32_t pts = 0, cts = 0;
	int32_t total_p = 0, total_c = 0;
	double gpa = 0., GPA = 0.;
	double target = 0.;
	int32_t remain = 0;

	while (1) {
		printf("\n\n");
		printf("1) Add the course grade.\n");
		printf("2) Delelte the course grade.\n");
		printf("3) GPA report.\n");
		printf("4) Target GPA.\n");
		printf("5) Exit.\n");
		printf("Your Choice (1-5): ");
		scanf("%d", &c);
		if (c == 5) break;
		else if (c < 1 || c > 5) {
			printf("Invalid input!\n");
			printf("You should input 1-5!\n");
			continue;
		}
		else {
			switch(c) {
				case 1:
					printf("Points (0-100): ");
					scanf("%d", &pts);
					if (pts < 0 || pts > 100) {
						printf("The score should be 0-100!\n");
						continue;
					}
					printf("Credits (0-4): ");
					scanf("%d", &cts);
					if (cts < 0 || cts > 4) {
						printf("The credits should be 0-4!\n");
						continue;
					}
					total_p += pts;
					total_c += cts;
					gpa += gpa_table(pts)*cts;
					GPA = gpa/total_c;
					i++;	
					break;
				case 2:
					if (i == 0) {
						printf("You have no score now!\n");
						printf("Please enter a score first!\n");
						continue;
					}
					printf("Points (0-100): ");
					scanf("%d", &pts);
					if (pts < 0 || pts > 100) {
						printf("The score should be 0-100!\n");
						continue;
					}
					printf("Credits (0-4): ");
					scanf("%d", &cts);
					if (cts < 0 || cts > 4) {
						printf("The credits should be 0-4!\n");
						continue;
					}
					total_p -= pts;
					total_c -= cts;
					gpa -= gpa_table(pts)*cts;
					GPA = gpa/total_c;
					i--;
					break;
				case 3:
					printf("Total Credits: %d\n", total_c);
					printf("GPA: %.2f\n", GPA);
					break;
				case 4:
					printf("Target GPA: ");
					scanf("%lf", &target);
					if (target < 0) {
						printf("The target should larger than 0!\n");
						continue;
					}
					printf("Remaining Credits: ");
					scanf("%d", &remain);
					if (remain < 0) {
						printf("Remaining cannot be negative!\n");
						printf("Are u kidding me?\n");
					}
					else if (remain == 0) {
						if (GPA < target) {
							printf("You are hopeless!\n");
							printf("Give up!\n");
							continue;
						}
						else {
							printf("You have already done!\n");
							continue;
						}
					}
					else {
						double avg = 0.;
						char *rank;
						avg = (target*(total_c+remain) - gpa)/remain;
						if (avg > 4.3) {
							printf("You are hopeless!\n");
							continue;
						}
						else if (avg >= 4.0) rank = "A+";
						else if (avg >= 3.7) rank = "A";
						else if (avg >= 3.3) rank = "A-";
						else if (avg >= 3.0) rank = "B+";
						else if (avg >= 2.7) rank = "B";
						else if (avg >= 2.3) rank = "B-";
						else if (avg >= 2.0) rank = "C+";
						else if (avg >= 1.7) rank = "C";
						else if (avg >= 1.0) rank = "C-";
						else if (avg >= 0.) rank = "D";
						else {
							printf("Something wrong!\n");
							continue;
						}
						printf("You should get at lease %s on average \x1b[31mfor\x1b[0m the remaining credits\n", rank);
					}
				break;
			}
		}
	}
	return 0;
}

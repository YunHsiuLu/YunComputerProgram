#include <stdio.h>

int main() {
	int ax = 0, ay = 0;
	int bx = 0, by = 0;
	int cx = 0, cy = 0;
	printf("Please enter the point A (x,y): ");
	scanf("%d, %d", &ax, &ay);
	printf("Please enter the point B (x,y): ");
	scanf("%d, %d", &bx, &by);
	printf("Please enter the point C (x,y): ");
	scanf("%d, %d", &cx, &cy);

	double m_c  = 0., cut_c = 0.;
	m_c = - (ax-bx) / (float)(ay-by);
	cut_c = cy - m_c * cx;
	printf("The line: y = %.2f * x + %.2f\n", m_c, cut_c);
	return 0;
}

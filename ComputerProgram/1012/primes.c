#include <stdio.h>
#include <stdlib.h>

int main() {
	int cnt = 0;
	printf("Please enter the number of primes: ");
	scanf("%d", &cnt);
	int * primes;
	primes = malloc(cnt*sizeof(int));
	primes[0] = 2;
	printf("%d is prime!\n", primes[0]);
	int c = 1;
	int runner = 3;
	int isPrime = 1;

	while (c < cnt) {
		isPrime = 1;
		for (int i = 0; i < c; i++) {
			if (runner % primes[i] == 0) {
				isPrime = 0;
				break;
			}
		}
		if (isPrime) {
			printf("%d is prime!\n", runner);
			primes[c] = runner;
			c++;
		}
		runner++;
	}
	return 0;
}

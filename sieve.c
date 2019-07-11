#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TOP 2000000000

char primes[TOP];

void sieve() {
	primes[0] = 1;
	primes[1] = 1;

	for (long i = 4; i <= TOP; i += 2)
		primes[i] = 1;

	for (long jump = 3; jump < TOP / 2; jump += 2)
		for (long i = jump * 2; i < TOP; i += jump)
			primes[i] = 1;
}

void print_largest() {
	for (long i = TOP; i > 0; i--)
		if (primes[i] == 0) {
			printf("Largest prime: %ld\n", i);
			return;
		}
}

void print_count() {
	long count = 0;
	for (long i = 0; i < TOP; i++)
		if (primes[i] == 0)
			count++;
	printf("Number of primes: %ld\n", count);
}

int main(int argc, char **argv) {
	sieve();
	print_largest();
	print_count();
	return 0;
}

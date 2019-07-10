#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TOP 2000000000

/* Should probably change to int */
long primes[TOP];
long prime_index = 0;

void find_primes() {
	primes[prime_index++] = 2;

	for (long n = 3; n < TOP; n += 2) {
		long sqrtn = sqrt(n);
		for (long i = 0; i < prime_index && primes[i] <= sqrtn; i++) {
			if (n % primes[i] == 0)
				goto NOADD;
		}
		primes[prime_index++] = n;
		NOADD: ;
	}
}

int main(int argc, char **argv) {
	find_primes();
	printf("Largest prime: %ld\n", primes[prime_index-1]);
	printf("Number of primes: %ld\n", prime_index);
	return 0;
}

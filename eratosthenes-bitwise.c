#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// https://stackoverflow.com/questions/2525310/how-to-define-and-work-with-an-array-of-bits-in-c
#define SetBit(A,k)     ( A[(k/8)] |= (1 << (k%8)) )
#define TestBit(A,k)    ( ( A[(k/8)] & (1 << (k%8)) ) == 0 )

#define TOP 2000000000

char primes[TOP/8];

// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
void eratosthenes() {
	SetBit(primes, 0);
	SetBit(primes, 1);

	long end = sqrt(TOP);
	for (long i = 2; i < end; i++)
		if (TestBit(primes, i))
			for (long j = i * i; j <= TOP; j += i)
				SetBit(primes, j);
}

void print_largest() {
	for (long i = TOP; i > 0; i--)
		if (TestBit(primes, i)) {
			printf("Largest prime: %ld\n", i);
			return;
		}
}

void print_count() {
	long count = 0;
	for (long i = 0; i < TOP; i++)
		if (TestBit(primes, i))
			count++;
	printf("Number of primes: %ld\n", count);
}

int main(int argc, char **argv) {
	eratosthenes();
	print_largest();
	print_count();
	return 0;
}

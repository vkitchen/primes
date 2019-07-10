#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// https://stackoverflow.com/questions/2525310/how-to-define-and-work-with-an-array-of-bits-in-c
#define SetBit(A,k)     ( A[(k/8)] |= (1 << (k%8)) )
#define TestBit(A,k)    ( A[(k/8)] & (1 << (k%8)) )

#define TOP 2000000000

char primes[TOP/8];

void eratosthenes() {
	SetBit(primes, 0);
	SetBit(primes, 1);

	for (long i = 4; i <= TOP; i += 2)
		SetBit(primes, i);

	long end = sqrt(TOP);
	for (long jump = 3; jump < end; jump += 2)
		for (long i = jump * jump; i < TOP; i += jump)
			SetBit(primes, i);
}

void print_largest() {
	for (long i = TOP; i > 0; i--)
		if (TestBit(primes, i) == 0) {
			printf("Largest prime: %ld\n", i);
			return;
		}
}

void print_count() {
	long count = 0;
	for (long i = 0; i < TOP; i++)
		if (TestBit(primes, i) == 0)
			count++;
	printf("Number of primes: %ld\n", count);
}

int main(int argc, char **argv) {
	eratosthenes();
	print_largest();
	print_count();
	return 0;
}

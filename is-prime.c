#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int is_prime(long num) {
	if (num <= 1)
		return 0;
	if (num == 2)
		return 1;
	if (num % 2 == 0)
		return 0;

	long top = sqrt(num);
	for (long div = 3; div < top; div += 2)
		if (num % div == 0)
			return 0;

	return 1;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s [number]\n", argv[0]);
		exit(1);
	}
	long num = strtol(argv[1], NULL, 10);
	if (is_prime(num))
		printf("%ld is prime\n", num);
	else
		printf("%ld is not prime\n", num);
	return 0;
}

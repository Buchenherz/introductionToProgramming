#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isprime(int number){	
	for(int i = 2; i < number; i++){
		/* If there is any number other than the number 
		 * itself that is divisible with % = 0, 
		 * no prime! */
		if ((i != number) && ((number % i) == 0)) {
			return false;
		}
	}
	/* Otherwise prime */
	return true;
}

int main(void) {
	int limit = 100;
	int input = 0;
	
	/* Inputs */
	printf("Check if prime (1: True, 0: False): "); scanf("%d", &input);
	printf("%d\n", isprime(input));
	printf("Enter to get primes to: "); scanf("%d", &limit);
	
	/* To get prime numbers from 2 to limit */
	for(int i = 2; i <= limit; i++){
		if (isprime(i)) {
			printf("%d\n", i);
		}
	}
	return EXIT_SUCCESS;	
}

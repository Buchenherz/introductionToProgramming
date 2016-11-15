#include <stdio.h> 
#include <stdlib.h>

int main(void) { 
	int a = 23.42; /* Double casted to int */
	int x = (short)1432123453; 
	/* Explicit casting to short // major overflow */
	long int y = (a|x)^a; 
	/* Bitwise operators */
	short int z = x * -2; 
	int u = 0xAAAA & (0x00F0 | 0xF000); 
	/* Bitwise AND and OR operators */
	int v; 
	int w = v ^ v;
	/* Number XOR itself is 0 */ 
	printf("a=%d\n", a); 
	printf("x=%d\n", x); 
	printf("y=%ld\n", y); 
	printf("z=%d\n", z); 
	printf("u=0x%X\n", u); 
	printf("v=%d\n", v); 
	printf("w=%d\n", w);

return EXIT_SUCCESS;

}
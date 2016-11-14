#include <stdlib.h>
#include <stdlio.h>

int main(void) { 
	float a = 1.2; 
	double x = sizeof(a) * 2 && 25 / printf("abc\n") ^ 2 + 1; 
	double y = ((short)a / 2 + (3 | 8) >> 2); 
	double z = a * 6; 
	double u = 0xBAECAB1E ? 1 << 1 : 0xDEADC0DE;
	double v = (u + z * 11) / 6; 
	double w = (int)(u + v * 10) / 2;

	printf("x=%lf\n", x); //x=1.000000
	printf("y=%lf\n", y); //y=2.000000
	printf("z=%lf\n", z); //z=7.200000
	printf("u=%lf\n", u); //u=2.000000
	printf("v=%lf\n", v); //v=13.533334
	printf("w=%lf\n", w); //w=68.000000


	return EXIT_SUCCESS;


}
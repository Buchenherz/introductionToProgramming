#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_leapyear(int year){
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
		return true;
	}
	return false;
}


int main(void) {
	for(int year = 1582; year <= 2400; year++){
		if (is_leapyear(year)) {
			printf("% d: True\n", year);
		} else
		printf("% d: False\n", year);
	}
	return EXIT_SUCCESS;
}
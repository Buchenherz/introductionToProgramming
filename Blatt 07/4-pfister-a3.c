#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* new_int(void){
	int my_new_int = 0;
	return &my_new_int;
}

//void length(int array[]) {
//	return sizeof(array) / sizeof(int); 
//}

bool is_true(void){
	int* ptr1 = 0x00;
	printf("%d %p\n", ptr1, &ptr1); 
	char* ptr2 = 0x08;
	printf("%d %p\n", ptr2, &ptr2); 
	ptr1 + 3;
	printf("%d %p\n", ptr1, &ptr1); 
	ptr2 + 4;
	printf("%d %p\n", ptr2, &ptr2);
	return ptr1 == ptr2;
}

int main(int argc, char *argv[]) {
	printf("%d\n", new_int());
//	int *make;
//	make = 3;
//	printf("%lu", sizeof(make));
	int array[] = {1,2,30};
	printf("Size of int: %lu\n", sizeof(int));
	printf("Size of array: %d\n", sizeof(array));
	int i = sizeof(array) / sizeof(int); 
	printf("%d\n", i);
	printf("is_True?: %d", is_true());
	return EXIT_SUCCESS;
}
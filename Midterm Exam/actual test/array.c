#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEM_COUNT 10

/* Predefining this because I can */

enum operations{
	ADDITION = 0,
	MULTIPLICATION
};

int arithmetic(int arr[], int length, int n, enum operations operation);

/* Simple list print */
void list_print(int array[]) { 
	printf("Array: [");
	for (int i = 0; i < MAX_ELEM_COUNT; i++) {
		if (i == MAX_ELEM_COUNT-1) {
			printf("%d", array[i]);
		} else
			printf("%d,", array[i]);
	}
	printf("]\n");
}

int main(void) {


	/* Fill array with numbers from 0 to MAX - 1 */	
	int array[MAX_ELEM_COUNT] = {};
	for(int i = 0; i < MAX_ELEM_COUNT; i++){
		array[i] = i+1;
	}
	
	/* Print array (testing purp.) */
	list_print(array);
	
	/* Magic */
	printf("%d\n", arithmetic(array, MAX_ELEM_COUNT, 2, ADDITION));
	
	return EXIT_SUCCESS;
}

int arithmetic(int arr[], int length, int n, enum operations operation){
	int sum = 0;
	int mul = 1;
	
	if (operation == 0) {
		/* Iterate over every n'th element */
		for(int i = 0; i < length; i += n){
			sum += arr[i];
		}
		return sum;
		
	} else if (operation == 1){
		
		for(int i = 0; i < length; i += n){
			mul *= arr[i];
		}
		return mul;
		
	}
	else {
		/* Default */
		printf("Wrong operation!\n");
		return -1;
	}
}
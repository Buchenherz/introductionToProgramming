#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 10

/* TODO: RNG Array gen in C */

/* TODO: Add more sort algorythms */

int list_print(int array[], int length) { 
	printf("[");
	for (int i = 0; i < CAPACITY; i++) {
		if (i == CAPACITY-1) {
			printf("%d", array[i]);
		} else
			printf("%d,", array[i]);
	}
	printf("]\n");
	return 1;
}

/* Welcome to Bubblesort */
void sort(int array[], int length){
	int n = length;
	while (true) {
		bool swapped = false;
		for (int i = 1 ;i <= n-1; i++) {
			if (array[i-1] > array[i]) {
				int tmp = array[i-1];
				array[i-1] = array[i];
				array[i] = tmp;
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	} 
	printf("Sorted array: "); printf("%d", list_print(array, length));
}

int main(void) {
	int array[CAPACITY] = {2,5,3,1,6,7,4,5,4,2}; 
	int length = 10;
	printf("Unsorted array: "); printf("%d", list_print(array, length));
	sort(array, length);
}
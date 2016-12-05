#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 10

void sort(int array[], int length);

int list_print(int list[], int length) { 
	printf("[");
	/* Using length gives me the option to only 
	 * print values within array */
	for (int i = 0; i < length; i++) {
		if (i == length-1) {
			printf("%d", list[i]);
		} else
			printf("%d,", list[i]);
	}
	printf("]\n");
	return 1;
}

int list_get(int list[], int length, int index) {
	if ((index >= CAPACITY)||(index < 0)) {
		printf("Error: Index out of range. Code 0\n");
		return 0;
	} 

	printf("Value of array at index %d is %d\n", index, list[index]);
	return list[index];
}

bool list_push_back(int list[], int* length, int capacity, int value) {
	/* checks if array is full */
	if (*length == CAPACITY) {
		printf("Error: There's not enough space for %d of us! (Array full error).\n", CAPACITY+1);
		return false;
	}
	/* length + 1 would be incorrect */
	list[*length] = value;
	
	/* Need this to be able to update value in main */
	*length += 1;
	
	printf("Added element %d at the end of list!\n", value);
	printf("The new array is: "); list_print(list, *length);
	return true;
}

int list_pop_back(int list[], int* length) { 
	if (*length <= 0) {
		printf("Error: Array is zero. Code 0\n");
		return 0;
	}
	/* length - 1 same as index */
	int last_item = list[*length-1];
	list[*length-1] = 0;	
	/* Need this to be able to update value in main */
	*length -= 1;
	printf("The last item of the array (%d) has been removed!\n", last_item);
	printf("The new array is: "); list_print(list, *length);

	return last_item;
}


int main(void) { 
	/* Var / arr declaration */
	int list[CAPACITY] = {6,1,4,5,2,23,45,3}; 
	int length = 10;
	

	
	while (true) {
		printf("Choose an option from below:\n");
		printf("/* 0: Exit, 1: Add element, 2: Remove last, 3: Show at index, 4: Print list, 5: Sort */\n");
		int option = 0;
		printf("Enter mode: ");
		scanf("%d", &option);
		
		/* Switch statement is difficult because of input */
		if (option == 0) {
			break;
		} else if (option == 1) {
			int value = 0;
			printf("Enter a value: "); scanf("%d", &value);
			list_push_back(list, &length, CAPACITY, value);
		} else if (option == 2) {
			list_pop_back(list, &length);
		} else if (option == 3) {
			int index = 0;
			printf("Enter an index: "); scanf("%d", &index);
			list_get(list, length, index);	
		} else if (option == 4) {
			list_print(list, length);
		} else if (option == 5) {
			sort(list, length);
		} else {
			/* Default fallback */
			printf("Please enter a valid option!\n");
		}
	}
	return EXIT_SUCCESS;

	/* TODO Testing */ 
	/*
	printf("List get index 2: "); list_get(array, length, 2);
	list_get(array, length, -1);
	printf("Original Array: "); list_print(array, length);
	list_push_back(array, &length, CAPACITY, 44);
	printf("New length: %d\n", length);
	list_pop_back(array, &length);
	return EXIT_SUCCESS;
	*/
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
	printf("Sorted array: "); list_print(array, length);
}

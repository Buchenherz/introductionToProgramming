#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 100

int list_get(int list[], int length, int index) {
	if ((index >= CAPACITY)||(index < 0)) {
		printf("Error: Index out of range. Code 0\n");
	}
	printf("Value of array at position %d is %d\n", index, list[index]);
	return list[index];
}

bool list_push_back(int list[], int* length, int capacity, int value) {
	if (*length == CAPACITY-1) {
		printf("Error: We need more room here!\n");
		return false;
	}
	// length + 1 would be incorrect 
	list[*length] = value;
	printf("Added element %d at the end of list!\n", value);
	// Need this to be able to update value in main
	*length += 1;	
	return true;
}

int list_pop_back(int list[], int* length) { 
	if (*length == 0) {
		printf("Error: Array is zero. Code 0\n");
	}
	// If length is 100, length alone would cause overflow
	int last_item = list[*length-1];
	list[*length-1] = 0;	
	// Need this to be able to update value in main
	*length -= 1;
	printf("The last item of the array (%d) has been removed!\n", last_item);
	return last_item;
}
int list_print(int list[], int length) { 
	printf("[");
	for (int i = 0; i < CAPACITY; i++) {
		if (i == CAPACITY-1) {
			printf("%d", list[i]);
		} else
			printf("%d,", list[i]);
	}
	printf("]\n");
	return 0;
}

int main(void) { 
	int list[CAPACITY] = {6,1,4,5}; 
	int length = 0; 
	/* TODO Testing */ 
	list_get(list, length, 2);
	list_push_back(list, &length, CAPACITY, 44);
	printf("New length: %d\n", length);
	printf("Array old: "); list_print(list, length);
	list_pop_back(list, &length);
	printf("Array new: "); list_print(list, length);
	return EXIT_SUCCESS; 
}
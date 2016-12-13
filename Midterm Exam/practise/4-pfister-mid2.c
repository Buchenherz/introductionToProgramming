#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 10

bool is_valid(int input){
	return ((input <= 100) && (input >= -100));
}

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

bool add_item(int list[], int* length, int capacity, int value){
		/* checks if array is full */
		if (*length == CAPACITY) {
			printf("Error: There's not enough space for %d of us! (Array full error).\n", CAPACITY+1);
			return false;
		}
		/* length + 1 would be incorrect */
		list[*length] = value;
		
		/* Need this to be able to update value in main */
		*length += 1;
		return true;
}

int min_value(int list[], int length){
	int min = list[0];
	for (int i = 1;i < length; i++) {
		if (list[i] < min) {
			min = list[i];
		}
	}
	return min;
}

int max_value(int list[], int length){
	int max = list[0];
	for (int i = 1;i < length; i++) {
		if (list[i] > max) {
			max = list[i];
		}
	}
	return max;
}

double average(int list[], float length){
	int sum = 0;
	for (int i = 0; i < length; i++){
		sum += list[i];
	}
	double average = sum / length;
	return average;
}


int main(void){
	int length = 0;
	int list[CAPACITY] = {0};
	int valid_inputs = 0;
	
	do {
		int option = -1;
		printf("0: Exit, 1: Add, 2: Print\n");
		printf("Choose an option: "); scanf("%d", &option);
		if (option == 0) {
			// Add print
			printf("The array is: "); list_print(list, length);	
			printf("Minimum is: %d\n", min_value(list, length));		
			printf("Maximum is: %d\n", max_value(list, length));
			printf("Average is: %f\n", average(list, length));
			printf("Number of valid inputs: %d\n", valid_inputs);
			break;
		} 
		else if (option == 1) {
			// Add
			int value = 0;
			printf("Enter value: "); scanf("%d", &value);
			if (!is_valid(value)) {
				printf("Error, out of range!\n");
				continue;
			}
			valid_inputs += 1;
			add_item(list, &length, CAPACITY, value);
		}
		else if (option == 2) {
			// list
			if (valid_inputs == 0){
				printf("Enter valid inputs first!\n");
				continue;
			}
			printf("The array is: "); list_print(list, length);	
			printf("Minimum is: %d\n", min_value(list, length));		
			printf("Maximum is: %d\n", max_value(list, length));
			printf("Average is: %f\n", average(list, length));
			printf("Number of valid inputs: %d\n", valid_inputs);		
		}
	} while (true);
	return EXIT_SUCCESS;
}
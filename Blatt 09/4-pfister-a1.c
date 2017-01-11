#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_ELEM_COUNT 10
#define RANDOM_TO 20

typedef enum {
	ADDITION,
	MULTIPLICATION
} operations;

int rng(int limit);
int arithmetic(int arr[MAX_ELEM_COUNT], int length, int n, operations operation);
// Fills array with random numbers (up to RANDOM_TO)
void fill_array(int arr[MAX_ELEM_COUNT], int length);

int main(void) {
	
	// Set time-seed for rand()
	srand(time(NULL));
	
	int array[MAX_ELEM_COUNT];
	fill_array(array, MAX_ELEM_COUNT);
	
	int n;
	printf("Enter n: "); scanf("%d", &n);
	
	// To let the user choose via command line
	char option[20];
OPTION:
	printf("Enter option: "); scanf("%s", &option[0]);
	operations operation;
	
	if (!strcmp(option, "ADDITION")) {
		operation = ADDITION;
	} else if (!strcmp(option, "MULTIPLICATION")) {
		operation = MULTIPLICATION;
	} else {	
		printf("Something went wrong\n");
		// I don't want to exit the whole program because of failed input
		// That's why I use goto
		goto OPTION;
	}
	
	printf("%d\n", arithmetic(array, MAX_ELEM_COUNT, n, operation));
	return EXIT_SUCCESS;
}

int rng(int limit){
	// Random number between 0 and limit-1
	int n = (rand() % limit) + 1;
	return n;
}

void fill_array(int arr[MAX_ELEM_COUNT], int length){
	for (int i = 0; i < length; i++){
		arr[i] = rng(RANDOM_TO);
	}
}

int arithmetic(int arr[MAX_ELEM_COUNT], int length, int n, operations operation){
	int sum = 0;
	int mul = 1;
	if (operation == MULTIPLICATION) {
		for (int i = 0;i < length; i+=n) {
			mul *= arr[i];
		}
		return mul;
	} else if (operation == ADDITION) {
		for (int i = 0;i < length;i+=n) {
			sum += arr[i];
		}
		return sum;
	}
	// In case something doesn't work out...
	return EXIT_FAILURE;
}
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int *iarray(int n){
	int *iptr = (int*)malloc(n * sizeof(*iptr));
	if (iptr != NULL)
	{
		for (int i = 0; i < n; i++)
		{
			iptr[i] = i + 1;
		}
	} else {
		exit(EXIT_FAILURE);
	}
	return iptr;
}

void print_array(int* arr, int n){
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int array_sum(int* arr, int n){
	int sum = 0;
	for (int i = 0; i < n; i++)
		{
			sum += arr[i];
		}
	return sum;
}

int main(int argc, char const *argv[])
{
	unsigned int n;
	printf("Please enter the number of integer itmes you want: "); scanf("%d", &n);
	int *arr = iarray(n);
	if (arr == NULL)
	{
		printf("Error with malloc!\n");
		return EXIT_FAILURE;
	}

	print_array(arr, n);
	
	// arr not free yet
	int sum = array_sum(arr, n);
	printf("%d\n", sum);
	
	// after freeing an array never ever touch it again (normally 😉)
	free(arr);

	print_array(arr, n);

	sum = array_sum(arr, n);
	printf("%d\n", sum);

	return EXIT_SUCCESS;
}

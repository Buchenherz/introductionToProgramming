#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int *iarray(int n){
	int *iptr = malloc(n * sizeof(*iptr));
	if (iptr != NULL)
	{
		for (int i = 0; i < n; i++)
		{
			iptr[i] = i + 1;
		}
	}
	return iptr;
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Please enter the number of integer itmes you want: "); scanf("%d", &n);
	int *arr = iarray(n);
	if (arr == NULL)
	{
		printf("Error with malloc!\n");
		return EXIT_FAILURE;
	}

	for (int i = 0; i < n; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	int sum = 0;

	// arr not free yet
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	printf("%d\n", sum);

	// freeing array
	free(arr);
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	printf("%d\n", sum);

	return EXIT_SUCCESS;
}

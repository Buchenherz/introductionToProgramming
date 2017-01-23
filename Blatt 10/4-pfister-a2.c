#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <stdbool.h>

struct Person { 
	char firstname[64]; 
	char lastname[64]; 
	int age; 
};

int Person_cmp_firstname(const void* x, const void* y){
	return strcmp(x, y);
}

int Person_cmp_lastname(const void* x, const void* y ) {
	return strcmp(x, y); 
}

int Person_cmp_age(const void* x, const void* y) {
	if (x > y) {
		return -1;
	}
	else if (x < y){
		return 1;
	}
	else {
		return 0;
	}
}

void input(struct Person *person_array[]){
	for (int i = 0; i < 3; i++)
	{
		printf("Enter person no. %d's First-/Lastname and age: ", i + 1);
		scanf("%s", person_array[i]->firstname);
		scanf("%s", person_array[i]->lastname);
		scanf("%d", &person_array[i]->age);
	}
}

void dynamicalize(struct Person *person_array[]){
	for (int i = 0; i < 3; i++)
	{
		// Allocate heap mem for every item of person_array
		person_array[i] = malloc(sizeof(struct Person));
	}
}

void print_persons(struct Person *person_array[]){
    for (int i = 0; i < 3; i++)
    {
    	printf("\n");
        printf("Person %d:\n", i + 1);
        printf("%s %s, who is %d years old.\n", person_array[i]->firstname, person_array[i]->lastname, person_array[i]->age);
    }
}

int main(int argc, char const *argv[])
{
	// Null pointer initialisation of an array of pters
	struct Person* person_array[3] = {NULL};

	dynamicalize(person_array);
	input(person_array);
	print_persons(person_array);

	printf("\n");
	printf("/*----------  Choose a sort option  ----------*/\n");
	printf("/*----------      Firstname: 1      ----------*/\n");
	printf("/*----------       Lastname: 2      ----------*/\n");
	printf("/*----------            Age: 3      ----------*/\n");
	int n = 0;
	scanf("%d", &n);

	switch(n){
		case 1: qsort(person_array, 3, sizeof(struct Person), Person_cmp_firstname); break;
		case 2: qsort(person_array, 3, sizeof(struct Person), Person_cmp_lastname); break;
		case 3: qsort(person_array, 3, sizeof(struct Person), Person_cmp_age); break;
		default: printf("Something went wrong...\n");
	}
	
	return EXIT_SUCCESS;
}
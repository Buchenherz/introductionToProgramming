#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Add to upper case later maybe?
#include <ctype.h>

struct Person { 
	char firstname[64]; 
	char lastname[64]; 
	int age; 
};

int Person_cmp_firstname(const void* x, const void* y){
	struct Person *first_name_x = (*(struct Person**) x);
	struct Person *first_name_y = (*(struct Person**) y);
	return strcmp(first_name_x->firstname,first_name_y->firstname);
}

int Person_cmp_lastname(const void* x, const void* y ) {
	struct Person *last_name_x = (*(struct Person**) x);
	struct Person *last_name_y = (*(struct Person**) y);
	return strcmp(last_name_x->lastname,last_name_y->lastname);
}

int Person_cmp_age(const void* x, const void* y) {
	struct Person *age_x = (*(struct Person**) x);
	struct Person *age_y = (*(struct Person**) y);
	return age_x->age - age_y->age;
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

void free_them_all(struct Person *person_array[]){
	for (int i = 0; i < 3 ; i++) {
		free(person_array[i]);
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
		case 1: qsort( person_array , 3 , sizeof(struct Person*), Person_cmp_firstname); break;
		case 2: qsort( person_array , 3 , sizeof(struct Person*), Person_cmp_lastname); break;
		case 3: qsort( person_array , 3 , sizeof(struct Person*), Person_cmp_age); break;
		default: printf("Something went wrong...\n");
	}
	print_persons(person_array);
	free_them_all(person_array);
	return EXIT_SUCCESS;
}
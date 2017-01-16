#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct Person{
	char firstname[64];
	char lastname[64];
	int age;
};

int Person_cmp_firstname(const void* x, const void* y);
int Person_cmp_lastname(const void* x, const void* y);
int Person_cmp_age(const void* x, const void* y);

int main() {

	struct Person p1 = {"", "", 0 };
	struct Person p2 = {"", "", 0 };
	struct Person p3 = {"", "", 0 };
	
	char firstname[64];
	char lastname[64];
	int age;
	scanf("%s", &firstname[0]);
	scanf("%s", &lastname[0]);
	scanf("%d", &age);
	// Must use strcpy func to pass string to struct element
	strcpy(p1.firstname, firstname);
	strcpy(p1.lastname, lastname);
	p1.age = age;
	
	// How to do this with loops in c99?
	scanf("%s", &firstname[0]);
	scanf("%s", &lastname[0]);
	scanf("%d", &age);
	strcpy(p2.firstname, firstname);
	strcpy(p2.lastname, lastname);
	p2.age = age;
	
	scanf("%s", &firstname[0]);
	scanf("%s", &lastname[0]);
	scanf("%d", &age);
	strcpy(p3.firstname, firstname);
	strcpy(p3.lastname, lastname);
	p3.age = age;

	Person_cmp_age(&p1.age, &p2.age);
	return EXIT_SUCCESS;
}

int Person_cmp_firstname(const void* x, const void* y){
	if (x < y)
		return -1;
	else if (x > y) {
		return 1;
	}
	return 0;
}

int Person_cmp_lastname(const void* x, const void* y){
	
}

int Person_cmp_age(const void* x, const void* y){
	
}
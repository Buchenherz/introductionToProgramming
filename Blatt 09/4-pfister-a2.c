#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 100

struct  List{
	int list[CAPACITY];
	int length;
};

int list_get(const struct List* list, int index);
bool list_push_back(struct List* list, int value);
int list_pop_back(struct List* list);
void list_print(const struct List* list);

int main(void) {
	int list[CAPACITY] = {0};
	struct List stack = {list[CAPACITY], 0};
	list_push_back(&stack, 21);
	list_push_back(&stack, 11);
	list_push_back(&stack, 1234);
	list_push_back(&stack, 3);
	list_push_back(&stack, 513);
	list_push_back(&stack, 1);
	list_push_back(&stack, 10);
	list_push_back(&stack, 98);
	list_push_back(&stack, 143);
	list_push_back(&stack, 24);
	printf("%d\n", list_pop_back(&stack));
	printf("%d\n", list_get(&stack, 3));
	list_print(&stack);
	return EXIT_SUCCESS; 	
}



int list_get(const struct List* list, int index) { 
	// length -1 to get index value
	if ((index > list->length - 1) || index < 0 || index >= CAPACITY) {
		return 0;
	}
	return list->list[index];
}
 
bool list_push_back(struct List* list, int value) {
	if (list->length >= CAPACITY) {
		return false;
	}
	list->list[list->length] = value;
	list->length += 1;
	return true;
} 

int list_pop_back(struct List* list) {
	if (list->length == 0) {
		return 0;
	}
	// -1 to get index
	int item = list->list[list->length-1];
	list->length -= 1;
	return item;
}

void list_print(const struct List* list) {
	if (list->length == 0) {
		printf("[No Element]\n");
	} else {
		printf("[");
		for (int i = 0;i < list->length;i++) {
			if (list->length - 1 == i) {
				printf("%d", list->list[i]);
			} else
			printf("%d, ", list->list[i]);
		}
		printf("]\n");
	}
}

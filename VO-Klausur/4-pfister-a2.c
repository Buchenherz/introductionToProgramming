#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char clear(char *input);
//char mirror(char *input);
char up(char *input);

int main(int argc, char *argv[]) {
	
	char *input = argv[1];
	char *manipulation = argv[2];
	// Testing
	printf("%s, %s\n", input, manipulation);
	
	for (int i = 0; i != EOF;i++) {
	char temp = manipulation[i];
	if (temp == '\0') 
		break;
		
	if (temp == 'c') {
		printf("c\n");
		clear(input);
		break;
		
	} else if (temp == 'm') {
		//mirror(input);
		printf("m\n");
	} else if (temp == 'r') {
		printf("r\n");
	} else if (temp == 'u') {
		up(input);
		printf("u\n");
	} else {
		printf("Not allowed!\n");
		return EXIT_FAILURE;
	}
	
}
	return EXIT_SUCCESS;
}

char clear(char *input){
	
	for (int i = 0; input[i] != '\0'; i++) {
		input[i] = '-';
	}
	printf("%s\n", input);
	return *input;
}

//char mirror(char *input){
//	char *input_save = input;
//	int i = 0;
//	for (int length = strlen(input); length >= 0;length--) {
//		output[i] = input_save[length];
//		i++;
//	}
//	
//	return *input;
//}

char up(char *input){
	for (int i = 0;input[i] != '\0';i++) {
		input[i] += 1;
	}
	return *input;
}


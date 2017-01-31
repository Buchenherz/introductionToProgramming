#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Boxer{
	char name[64]; // no name will be longer than 64 chars
	int wins;
	double weight;
} boxer;

boxer inputBoxer(void){
	boxer boxer = {};
	printf("Enter boxer name, number of wins, and weight: ");
	scanf("%s", boxer.name);
	scanf("%d", &boxer.wins);
	scanf("%lf", &boxer.weight);
	return boxer;
}

void printBoxer(boxer boxer){
		printf("%s\t%d\t%f\n", boxer.name, boxer.wins, boxer.weight);
		printf("\n");
}

int main(int argc, char *argv[]) {
	int n;
	printf("Choose number of Boxers: "); scanf("%d", &n);
	
	boxer *heavy_boxers = malloc(n * sizeof(boxer));
	boxer *light_boxers = malloc(n * sizeof(boxer));

	if ((heavy_boxers == NULL) || light_boxers == NULL)	{
		printf("Error with malloc!\n");
		return EXIT_FAILURE;
	}
	
	int heavy_counter = 0;
	int light_counter = 0;
	
	for (int i = 0; i < n ;i++) {
		boxer boxer = inputBoxer();
		if (boxer.weight >= 100.0) {
			heavy_boxers[heavy_counter] = boxer;
			heavy_counter += 1;
		} else {
			light_boxers[light_counter] = boxer;
			light_counter += 1;
		}

		for (int j = 0;j < heavy_counter;j++) {
			if (j == 0) {
				printf("Heavyweights:\nName:\tWins:\tWeight:\n");
			}
			printBoxer(heavy_boxers[j]);
		}

		for (int j = 0;j < light_counter;j++) {
			if (j == 0) {
				printf("Lightweights:\nName:\tWins:\tWeight:\n");
			}
			printBoxer(light_boxers[j]);
		}
	}
	
	free(heavy_boxers);
	free(light_boxers);
	return EXIT_SUCCESS;
}


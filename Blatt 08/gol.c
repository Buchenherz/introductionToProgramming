#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	bool dead;
} status;

void write_pbm(const char* filepath, size_t width, size_t height,
			   const bool array[height][width]);

int rng(){
	// Random number between 1 and 100
	/* When two lines of code cost you half an hour...
	 * Time changes not quickly enough */
	uint32_t n = arc4random_uniform(100);
	return n;
}

void fill_array(int percentage, int height, int width, int array[height][width]);

void print_matrix(int height, int width, int a[height][width]) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			printf("%2d ", a[i][j]);
		printf("\n");
	}
}

void step(int height, int width, int current[height][width], int next[height][width]){
	int living = 0, dead = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			for (int m = -1; m <= 1; m++) {
				for (int n = -1; n <= 1; n++){
					if (m == n) {
						continue;
					}
					else if (current[i+m][j+n] != true && current[i+m][j+n] != false){
					dead += 1;
					continue;
					printf("%d", current[i+m][j+n]);
					}
					else if (current[i+m][j+n] == true) {
						living += 1;
					}
					else if (current[i+m][j+n] == false) {
						dead += 1;
					}
				}
			}
		}
	}
	printf("dead: %d, living: %d", dead, living);
}

int main(int argc, const char *argv[]){
	// Needs to be 5 because ./gol counts as one argument
	if (argc != 5) {
		printf("Usage: ./gol <width> <height> <fill-rate> <steps>");
		return EXIT_FAILURE;
	}
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	int percentage = atoi(argv[3]);
	// int steps = atoi(argv[4]);
	
	int current[height][width];
	int next[height][width];
	
	fill_array(percentage, height, width, current);
	print_matrix(height, width, current);
	step(height, width, current, next);
	// write_pbm("frame1.pbm", width, height, current);
	
	return EXIT_SUCCESS;
}

void fill_array(int percentage, int height, int width, int array[height][width]){
	for (int i = 0; i < height; i++) {
		for (int j = 0;j < width; j++) {
			int random_number = 0;
			random_number = rng();
			if (random_number <= percentage) {
				array[i][j] = true;
			} else {
				array[i][j] = false;
			}
		}
	}
}

void write_pbm(const char* filepath, size_t width, size_t height,
			   const bool array[height][width]) {
	
	assert(filepath != NULL);
	assert(array != NULL);
	
	/* Open file for writing */
	FILE* out = fopen(filepath, "w");
	if (out == NULL) {
		perror("write_pbm: fopen");
		exit(EXIT_FAILURE);
	}
	
	/* Magic number + dimensions */
	fprintf(out, "P1\n%ld %ld\n", width, height);
	
	/* Dump array */
	for (size_t h = 0; h < height; ++h) {
		for (size_t w = 0; w < width; ++w) {
			fprintf(out, "%c", array[h][w] ? '1' : '0');
		}
		fprintf(out, "\n");
	}
	
	/* All done */
	fclose(out);
}
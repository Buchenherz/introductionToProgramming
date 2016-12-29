#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
	bool dead;
} cell;

void write_pbm(const char* filepath, size_t width, size_t height,
			   const bool array[height][width]);

int rng(){
	// Random number between 1 and 100
	/* When two lines of code cost you half an hour...
	 * Time changes not quickly enough */
	uint32_t n = arc4random_uniform(100);
	return n;
}

void print_matrix(int height, int width, int a[height][width]) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			printf("%2d ", a[i][j]);
		printf("\n");
	}
}


void step(int height, int width, int current[height][width], int next[height][width], cell cell_nr[height*width-1]){
	for (int i = 0; i < height*width; i++) {
		// Dead or alive extreme counter
		int dead = 0, alive = 0;
		int x = cell_nr[i].x;
		int y = cell_nr[i].y;
		
		// Second x
		// Let's fill these counters
		for (int k = -1; k <= 1; k++) {
			// Second y
			for (int j = -1; j <= 1; j++) {
				if (j == 0 && k == 0) {
					continue;
				// Check if index is out of bounce
				} else if ((x+k) < 0 || (y+j) < 0 || (x+k) >= height || (y+j) >= width) {
					dead += 1;
					continue;
				} else if (current[x+k][y+j] == true){
					alive += 1;
				} else if (current[x+k][y+j] == false){
					dead += 1;
				}
			}
		}
		printf("alive: %d, dead: %d\n", alive, dead);
		// Do own function
		// If current cell is dead
		if (current[x][y] == false) {
			if (alive == 3) {
				// you need to do a function for setting x / y / deadth props
				next[x][y] = true;
			} else {
				next[x][y] = false;
			}
		}
		// If current cell is alive 
		else if (current[x][y] == true) {
			if (alive <= 1) {
				next[x][y] = false;
			} else if ((alive == 2) || (alive == 3)) {
				next[x][y] = true;
			} else if (alive >= 3) {
				next[x][y] = false;
			}
		}
		

	}
	print_matrix(height, width, next);
}






cell fill_array(int percentage, int height, int width, int array[height][width], cell cell_nr[height*width-1]){
	int counter = 0;
	while (counter < (height*width)) {
		for (int i = 0; i < height; i++) {
			for (int j = 0;j < width; j++) {
				int random_number = 0;
				random_number = rng();
				if (random_number <= percentage) {
					cell_nr[counter] = (cell){i, j, false};
					array[i][j] = true;
				} else {
					cell_nr[counter] = (cell){i, j, true};
					array[i][j] = false;
				}
				counter += 1;
			}
		}
	}
	return *cell_nr;
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
	
	// height / width really should be width / height imo 
	int current[height][width];
	int next[height][width];
	
	cell cell_nr[width*height-1];
	
	fill_array(0, height, width, next, cell_nr);
	fill_array(percentage, height, width, current, cell_nr);
	print_matrix(height, width, current);
	printf("\n%d\n", cell_nr[1].y);
	step(height, width, current, next, cell_nr);
	// write_pbm("frame1.pbm", width, height, current);
	
	return EXIT_SUCCESS;
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
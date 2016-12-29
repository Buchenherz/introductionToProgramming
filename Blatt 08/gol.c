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
			   const int array[height][width]);

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
			printf("%2d ", a[j][i]);
		printf("\n");
	}
	printf("\n");
}


int initialize_empty(int width, int height, int next[height][width]){
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			next[j][i] = 0;
	}
	return **next;
}

int clone_array(int width, int height, int source[height][width], int clone[height][width]){
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			clone[j][i] = source[j][i];
	}
	return **clone;
}


void step(int height, int width, int current[height][width], int next[height][width], cell cell_nr[height*width-1]){
	int cellcount = 0;
	// printf("%d: %2d %2d \n", 8, cell_nr[8].x, cell_nr[8].y);
	initialize_empty(width, height, next);
	do {
		// spaghetti fix
		cell_nr[height*width-1].x = width-1;
		cell_nr[height*width-1].y = height-1;
		// Dead or alive extreme counter
		int dead = 0, alive = 0;
		int x = cell_nr[cellcount].x;
		int y = cell_nr[cellcount].y;
		//printf("%d: %2d %2d \n", cellcount, cell_nr[cellcount].x, cell_nr[cellcount].y);
		cellcount += 1;
		// Second x (searchX)
 		// Let's fill these counters
		for (int sx = -1; sx <= 1; sx++) {
			// Second y (searchY)
			for (int sy = -1; sy <= 1; sy++) {
				// We want to skip the current cell
				if (sx == 0 && sy == 0) {
					continue;
				// Check if index is out of bounce
				} else if (((x+sx) < 0) || ((y+sy) < 0) || (x+sx) >= width || (y+sy) >= height) {
					dead += 1;
					continue;
				} else if (current[x+sx][y+sy] == true){
					alive += 1;
				} else if (current[x+sx][y+sy] == false){
					dead += 1;
				}
			}
		}
		//printf("alive: %d, dead: %d\n", alive, dead);
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
		
	} while (cellcount < height*width);
	write_pbm("frame*.pbm", width, height, current);
	clone_array(width, height, next, current);
}






cell fill_array(int percentage, int height, int width, int array[height][width], cell cell_nr[height*width-1]){
	int counter = 0;
	do {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				int random_number = 0;
				random_number = rng();
				if (random_number <= percentage) {
					cell_nr[counter] = (cell){j, i, false};
					array[j][i] = true;
				} else {
					cell_nr[counter] = (cell){j, i, true};
					array[j][i] = false;
				}
				counter += 1;
			}
		}
	} while (counter < (height*width));
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
	
	
	fill_array(percentage, height, width, current, cell_nr);
	print_matrix(height, width, current);

	step(height, width, current, next, cell_nr);
	
	print_matrix(height, width, current);
	step(height, width, current, next, cell_nr);
	print_matrix(height, width, current);
	
	// write_pbm("frame1.pbm", width, height, current);
	
	return EXIT_SUCCESS;
}



void write_pbm(const char* filepath, size_t width, size_t height,
			   const int array[height][width]) {
	
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
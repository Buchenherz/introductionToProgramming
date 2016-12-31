#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 10

typedef enum{
	horizontal, 
	vertical
} orientation;

typedef struct{
	orientation orientation;
	int start_x;
	int start_y;
	int length;
	int health;
	int nr;
	bool alive;
} ship; 


int rng(int limit);

void clrscr(void);

void create_battlefield(int battlefield[WIDTH][HEIGHT]);

orientation get_random_orientation(void);

int set_random_start_x(void);

int set_random_start_y(void);

void print_battlefield(int battlefield[WIDTH][HEIGHT]);

ship create_ship(orientation orientation, int start_x, int start_y, int length, int health, bool alive);

void set_ship(ship *_ship, int battlefield[WIDTH][HEIGHT]);

int main(int argc, char *argv[]) {
	
	int battlefield[WIDTH][HEIGHT];
	create_battlefield(battlefield);	
	
	// Will be used to count down ships
	int ship_amount = 10;
	
	
	
	/* While there may be better ways to do this, 
	 * it might help for debugging later on */
	ship ship_array[10] = {
		{get_random_orientation(), set_random_start_x(), set_random_start_y(), 5, 5, 0, true},
		{get_random_orientation(), set_random_start_x(), set_random_start_y(), 4, 4, 1, true}, 
		{get_random_orientation(), set_random_start_x(), set_random_start_y(), 4, 4, 2, true},
		{get_random_orientation(), set_random_start_x(), set_random_start_y(), 3, 3, 3, true},
		{get_random_orientation(), set_random_start_x(), set_random_start_y(), 3, 3, 4, true},
		{get_random_orientation(), set_random_start_x(), set_random_start_y(), 3, 3, 5, true},
		{get_random_orientation(), set_random_start_x(), set_random_start_y(), 2, 2, 6, true},
		{get_random_orientation(), set_random_start_x(), set_random_start_y(), 2, 2, 7, true},
		{get_random_orientation(), set_random_start_x(), set_random_start_y(), 2, 2, 8, true},
		{get_random_orientation(), set_random_start_x(), set_random_start_y(), 2, 2, 9, true}	
		};
	
	
	for (int i = 0; i < ship_amount; i++) {
		set_ship(&ship_array[i], battlefield);
	}
	
	print_battlefield(battlefield);
	
	return EXIT_SUCCESS;
}

int rng(int limit){
	// Random number between 0 and limit-1
	// Need 0 for index later
	uint32_t rng = arc4random_uniform(limit);
	return rng;
}

ship create_ship(orientation orientation, int start_x, int start_y, int length, int health, bool alive){
	return (ship){orientation, start_x, start_y, length, health, alive};
}

void create_battlefield(int battlefield[WIDTH][HEIGHT]){
	for(int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++) {
			// Set all initial values to 0;
			battlefield[x][y] = 0;
			// Just testing if coord-system works
			 //battlefield[1][3] = 1;
			printf(" ~");
		}
		printf("\n");
	}
}

void clrscr(void)
{
	system("@cls||clear");
}

void print_battlefield(int battlefield[WIDTH][HEIGHT]){
	clrscr();
	for(int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++) {
			printf("%2d", battlefield[x][y]);
		}
		printf("\n");
	}
}

orientation get_random_orientation(void){
	if (rng(50)<25) 
		return horizontal;
	return vertical;
}

int set_random_start_x(void){
	return rng(WIDTH);
}

int set_random_start_y(void){
	return rng(HEIGHT);
}

void set_ship(ship *_ship, int battlefield[WIDTH][HEIGHT]){
	while (true) {
	CHECK:
		printf("%d %d\n %u\n", _ship->start_x, _ship->start_y, _ship->orientation);
		if (_ship->orientation == horizontal) {
			// Out of bounce detection
			if ((_ship->start_x+_ship->length) < WIDTH && (battlefield[_ship->start_x][_ship->start_y] == 0)) {
				for (int x = _ship->start_x; x < _ship->start_x+_ship->length; x++) {
					for (int buffer = -1; buffer <=1; buffer++){
						// Nearby boat detection
						if ((battlefield[x][_ship->start_y+buffer] != 0) || (battlefield[x+buffer][_ship->start_y] != 0)) {
							_ship->start_x = set_random_start_x();
							_ship->start_y = set_random_start_y();
							_ship->orientation = get_random_orientation();
							goto CHECK;
						} 
					}
				}
				for (int x = _ship->start_x; x < _ship->start_x+_ship->length;x++){
					battlefield[x][_ship->start_y] = _ship->length;
				}
			} else {
				_ship->start_x = set_random_start_x();
				_ship->start_y = set_random_start_y();
				_ship->orientation = vertical;
				continue;
			}
		} else if (_ship->orientation == vertical) {
			if ((_ship->start_y + _ship->length) < HEIGHT && (battlefield[_ship->start_x][_ship->start_y] == 0)) {
				for (int y = _ship->start_y; y < _ship->start_y+_ship->length; y++) {
					for (int buffer = -1; buffer <=1; buffer++){
						if (battlefield[_ship->start_x+buffer][y] != 0 || (battlefield[_ship->start_x][y+buffer] != 0)) {
							_ship->start_x = set_random_start_x();
							_ship->start_y = set_random_start_y();
							_ship->orientation = get_random_orientation();
							goto CHECK;
						}
					}
				}
				for (int y = _ship->start_y; y < _ship->start_y+_ship->length;y++){
					battlefield[_ship->start_x][y] = _ship->length;
				}
			} else {
				_ship->start_x = set_random_start_x();
				_ship->start_y = set_random_start_y();
				_ship->orientation = horizontal;
				continue;
			}
		}
		break;
	}
	print_battlefield(battlefield);	
}






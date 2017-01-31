#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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
	bool placed;
	bool alive;
} ship; 


int rng(int limit);

void clrscr(void);

void create_battlefield(int battlefield[WIDTH][HEIGHT]);

orientation get_random_orientation(void);

int set_random_start_x(void);

int set_random_start_y(void);

void print_battlefield(int battlefield[WIDTH][HEIGHT]);

void print_no_cheat(int battlefield[WIDTH][HEIGHT]);

void update_ship(ship *_ship, orientation orientation, int start_x, int start_y, int length, int health, int nr, bool placed, bool alive);

void set_ship(ship *_ship, int battlefield[WIDTH][HEIGHT]);

void search_ship(ship ship_array[10], int shoot_x, int shoot_y, int *alive_counter);

bool shoot(ship ship_array[10], int battlefield[WIDTH][HEIGHT], int shoot_x, int shoot_y, int *alive_counter);

int main(int argc, char *argv[]) {
	
	// Set random seed	
	srand(time(NULL));
	
	int battlefield[WIDTH][HEIGHT];
	create_battlefield(battlefield);	
	
	// Will be used to count down ships
	int ship_amount = 10;
	
	/* While there may be better ways to do this, 
	 * it might help for debugging later on 
	 * Just default values btw. */
	ship ship_array[10] = {
		{horizontal, 0, 0, 5, 5, 0, false, true},
		{horizontal, 0, 0, 4, 4, 1, false, true}, 
		{horizontal, 0, 0, 4, 4, 2, false, true},
		{horizontal, 0, 0, 3, 3, 3, false, true},
		{horizontal, 0, 0, 3, 3, 4, false, true},
		{horizontal, 0, 0, 3, 3, 5, false, true},
		{horizontal, 0, 0, 2, 2, 6, false, true},
		{horizontal, 0, 0, 2, 2, 7, false, true},
		{horizontal, 0, 0, 2, 2, 8, false, true},
		{horizontal, 0, 0, 2, 2, 9, false, true}	
		};
	
	
	for (int i = 0; i < ship_amount; i++) {
		// I had much trouble with runtime, so for the final two ships, i go trough the array without randomization 
		// If the battlefield with / height is larger, this would not be neccessary
		while (ship_array[i].placed == false) {
			if (ship_array[i].nr < 8){
				update_ship(&ship_array[i], get_random_orientation(), set_random_start_x(), set_random_start_y(), ship_array[i].length, ship_array[i].health, ship_array[i].nr, ship_array[i].placed, ship_array[i].alive);
				set_ship(&ship_array[i], battlefield);
			} else {
				orientation fixed_orientation = get_random_orientation();
				int y = 0;
				int x = 0;
				while(y < HEIGHT && ship_array[i].placed == false){
					while(x < WIDTH && ship_array[i].placed == false) {
						update_ship(&ship_array[i], fixed_orientation, x, y, ship_array[i].length, ship_array[i].health, ship_array[i].nr, ship_array[i].placed, ship_array[i].alive);
						set_ship(&ship_array[i], battlefield);
						x++;
						if (x == WIDTH) {
							x = 0;
							break;
						}
					}
					y++;
					if (x == 0 && y == 10) {
						// swap orientation if no field found
						print_battlefield(battlefield);
						fixed_orientation = get_random_orientation();
						x = 0;
						y = 0;
					}
				}
			}
		}
	}
	
//	print_battlefield(battlefield);
	
	int alive_counter = 10;
	int shoot_x = 0;
	int shoot_y = 0;
	
	while (alive_counter > 0) {

//		for(shoot_x; shoot_x < 10; shoot_x++){
//			for (shoot_y; shoot_y < 10; shoot_y++) {
//				shoot(ship_array, battlefield, shoot_x, shoot_y, &alive_counter);
//				print_no_cheat(battlefield);
//			}
//			shoot_y = 0;
//		}
		scanf("%d %d", &shoot_x, &shoot_y);
		shoot(ship_array, battlefield, shoot_x, shoot_y, &alive_counter);
		print_no_cheat(battlefield);
	}
	
	printf("\nCongrats, you win!\n");
	
	return EXIT_SUCCESS;
}

int rng(int limit){
	// Random number between 0 and limit-1
	// Need 0 for index later
	int n = (rand() % limit) + 1;
	return n;
}

void update_ship(ship *_ship, orientation orientation, int start_x, int start_y, int length, int health, int nr, bool placed, bool alive){
	_ship->orientation = orientation;
	_ship->start_x = start_x;
	_ship->start_y = start_y;
	_ship->length = length;
	_ship->health = health;
	_ship->nr = nr;
	_ship->placed = placed;
	_ship->alive = alive;
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

void print_no_cheat(int battlefield[WIDTH][HEIGHT]){
	clrscr();
	for(int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++) {
			switch (battlefield[x][y]) {
				case 0: printf("~  "); break;
				case -1: printf(" ◎ "); break;
				case -2: printf(" ✕ "); break;
				case -3: printf(" ✕ "); break;
				case -4: printf(" ✕ "); break;
				case -5: printf(" ✕ "); break;
				default: printf("~  ");
			}
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
		// printf("%d %d\n %u\n", _ship->start_x, _ship->start_y, _ship->orientation);
		if (_ship->orientation == horizontal) {
			// Out of bounce detection
			if ((_ship->start_x+_ship->length) < WIDTH && (battlefield[_ship->start_x][_ship->start_y] == 0)) {
				for (int x = _ship->start_x; x < _ship->start_x+_ship->length; x++) {
					for (int buffer = -1; buffer <=1; buffer++){
						// Nearby boat detection
						if ((battlefield[x][_ship->start_y+buffer] != 0) || (battlefield[x+buffer][_ship->start_y] != 0)) {
							if (((x-1 < 0) || (x+1 >= WIDTH)) && (battlefield[x][_ship->start_y+buffer] <= 0)) {
								continue;
							}
							// Need to break out of 2 for loops, so I use goto here. 
							goto END;
						}
					}
				}
				for (int x = _ship->start_x; x < _ship->start_x+_ship->length; x++){
					battlefield[x][_ship->start_y] = _ship->length;
				}
			} else {
				break;
			}
		} else if (_ship->orientation == vertical) {
			if ((_ship->start_y + _ship->length) < HEIGHT && (battlefield[_ship->start_x][_ship->start_y] == 0)) {
				for (int y = _ship->start_y; y < _ship->start_y+_ship->length; y++) {
					for (int buffer = -1; buffer <=1; buffer++){
						if (battlefield[_ship->start_x+buffer][y] != 0 || (battlefield[_ship->start_x][y+buffer] != 0)) {
							if (((y-1 < 0) || (y+1 >= HEIGHT)) && (battlefield[_ship->start_x+buffer][y] <= 0)) {
								continue;
							}
							goto END;
						}
					}
				}
				for (int y = _ship->start_y; y < _ship->start_y+_ship->length;y++){
					battlefield[_ship->start_x][y] = _ship->length;
				}
			} else {
				break;
			}
		}
		_ship->placed = true;
	END:
		break;
	}
	// print_battlefield(battlefield);
}

void search_ship(ship *_ship, int shoot_x, int shoot_y, int *alive_counter){
	for (int search = -1*_ship->length+1; search < _ship->length; search++) {
		if ((_ship->orientation == horizontal)&&(_ship->start_x+search == shoot_x)&&(_ship->start_y == shoot_y)) {
			_ship->health -= 1;
			if ((_ship->health == 0) && (_ship->alive == true)) {
				_ship->alive = false;
				*alive_counter -= 1;
			}
			// We could loose much health if we don't break here
			break;
		} else if ((_ship->orientation == vertical)&&(_ship->start_y+search == shoot_y)&&(_ship->start_x == shoot_x)) {
			_ship->health -= 1;
			if ((_ship->health == 0) && (_ship->alive == true)) {
				_ship->alive = false;
				*alive_counter -= 1;
			}
			// We could loose much health if we don't break here
			break;
		}	
	}
}

bool shoot(ship ship_array[10], int battlefield[WIDTH][HEIGHT], int shoot_x, int shoot_y, int *alive_counter){
	if (shoot_x < 0 || shoot_x >= WIDTH || shoot_y < 0 || shoot_y >= HEIGHT) {
		printf("You can only shoot from (0/0) to (%d/%d)\n", WIDTH-1, HEIGHT-1);
		return false;
	}
	int field = battlefield[shoot_x][shoot_y];
	if (field == 0) {
		// Im using -1 for water hit
		battlefield[shoot_x][shoot_y] = -1;
		return false;
	} else if (field == 2) {
		// search ship from i to j  
		for (int i = 6; i <= 9; i++) {
			// maybe add hit property so we can break outa this early
			search_ship(&ship_array[i], shoot_x, shoot_y, alive_counter);
		}
			battlefield[shoot_x][shoot_y] = -2;
			return true;
	} else if (field == 3) {
		for (int i = 3; i <= 5; i++) {
			search_ship(&ship_array[i], shoot_x, shoot_y, alive_counter);
		}
			battlefield[shoot_x][shoot_y] = -3;
			return true;
	} else if (field == 4) {
		for (int i = 1; i <= 2; i++) {
			search_ship(&ship_array[i], shoot_x, shoot_y, alive_counter);
		}
			battlefield[shoot_x][shoot_y] = -4;
			return true;
	} else if (field == 5){
		/* Because there only is one ship of this size, 
		 * there is no need for an extra func call */
		ship_array[0].health -= 1;
		if (ship_array[0].health == 0) {
			ship_array[0].alive = false;
		}
		*alive_counter -= 1;
		battlefield[shoot_x][shoot_y] = -5;
		return true;
	} else {
		return false;
	}
}




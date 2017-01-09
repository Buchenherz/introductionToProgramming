#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum {
	north,
	east,
	south,
	west,
} options;
	
typedef struct {
	int r_id;
	int r_x;
	int r_y;
	bool visited;
	char name[20];
} room;
	
typedef struct {
	bool npc;
	int health;
	room position_r;
	char player_name[15];
	bool alive;
	int key_s;
} player;

void help(void);
void clrscr(void);

int main(int argc, char *argv[]) {

	printf("Something jada jada jada\n");
	
	while(true){
		char input[] = "";
		scanf("%s", &input);
	
		if (!strcmp(input, "help")) {
			help();
			continue;
		} else if (!strcmp(input, "north")){
			continue;
		} else if (!strcmp(input,"east")){
			continue;
		} else if (!strcmp(input,"south")){
			continue;
		} else if (!strcmp(input,"west")){
			continue;
		} 
		
		else if (strcmp(input, "")) {
			printf("Seems like you don't really know what you are doing, try 'help'\n");
		}
	}
}

void help(void){
	clrscr();
	printf("Huh, nice to see you here adventurer! I heard you shouting for some help...\n");
	printf("Your basic commands are: north (to go north), south (to go south), east and west. You can also input the look command, to get a grasp of what you are looking at.\n");
}

void clrscr(void)
{
	system("@cls||clear");
	printf("\n");
}
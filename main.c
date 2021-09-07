#include "game.h"

int main()
{
	int select = 0;
	int quit = 0;
	while(!quit){
	Menu();
	scanf("%d", &select);
	switch(select){
		case 1:
			Game();
			break;
		case 0:
			quit = 1;
			printf("Goodbye\n");
			break;
		default:
			printf("Enter error!Please try again!\n");
			break;
	}
	}
	return 0;
}

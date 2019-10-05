
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//tentative
#define GRID_HEIGHT 4
#define GRID_WIDTH 4

int main(void) {
	
	int neighbors, j;
	int i = 1;
	
	
	//temporary just for testing
	bool grid[GRID_HEIGHT][GRID_WIDTH] = { {1,0,0,0},
										   {1,1,0,0},
										   {1,0,0,0},
										   {0,0,0,0} };
	
	
	
	int changer_grid[GRID_HEIGHT][GRID_WIDTH];  
	/* to store the changes to be made to the grid
	 * (default)0 = no change, 1 = kill, 2 = bring to life*/
	
	 
	
	
	 //INITIAL GRID
	for (int x = 0; x < GRID_HEIGHT; x++) {
		for (int y = 0; y < GRID_WIDTH; y++) {

			if (grid[x][y] == 1)
				printf("#");
			else
				printf(" ");
		}

		printf("\n");
	}

	//GOD LOOP
	while (i == 1) {
		getch();

		
		//checker loop (clusterfuck)
		for (int x = 0; x < GRID_HEIGHT; x++) {
			for (int y = 0; y < GRID_WIDTH; y++) {

				
				//_______________________________________________________________________________________________
				//to count the number of neighbors the cell has:

				if (x == 0 && y == 0) //top left corner
					neighbors = grid[0][1] + grid[1][0] + grid[1][1];

				else if (x == 0 && y != 0 && y != GRID_WIDTH - 1) //top row
					neighbors = grid[0][y - 1] + grid[0][y + 1] + grid[1][y - 1] + grid[1][y] + grid[1][y + 1];

				else if (x == 0 && y == GRID_WIDTH - 1) //top right corner
					neighbors = grid[0][y - 1] + grid[1][y] + grid[1][y - 1];

				else if (x != 0 && x != GRID_HEIGHT - 1 && y == 0) //left column
					neighbors = grid[x - 1][0] + grid[x + 1][0] + grid[x - 1][1] + grid[x][1] + grid[x + 1][1];

				else if (x != 0 && x != GRID_HEIGHT - 1 && y == GRID_WIDTH - 1)//right column
					neighbors = grid[x - 1][y] + grid[x + 1][y] + grid[x - 1][y - 1] + grid[x][y - 1] + grid[x + 1][y - 1];

				else if (x == GRID_HEIGHT - 1 && y == 0) //bottom left corner
					neighbors = grid[x - 1][0] + grid[x][1] + grid[x - 1][1];

				else if (x == GRID_HEIGHT - 1 && y == GRID_HEIGHT - 1) //bottom right corner
					neighbors = grid[x][y - 1] + grid[x - 1][y] + grid[x - 1][y - 1];

				else if (x == GRID_HEIGHT - 1 && y != 0 && y != GRID_WIDTH - 1) //bottom column
					neighbors = grid[x][y - 1] + grid[x][y + 1] + grid[x - 1][y - 1] + grid[x - 1][y] + grid[x - 1][y + 1];

				else //everywhere else
					neighbors = grid[x - 1][y - 1] + grid[x][y - 1] + grid[x + 1][y - 1] + grid[x - 1][y] +
					grid[x + 1][y] + grid[x - 1][y + 1] + grid[x][y + 1] + grid[x + 1][y + 1];

				
				
				//_____________________________________________________________________________________________
				//checking conditions for change and assigning to the change_grid for use in the changer loop
				
				//dead and has 3 neighbors
				if (grid[x][y] == 0 && neighbors == 3)
					changer_grid[x][y] = 2;

				//alive
				if (grid[x][y] == 1) {

					//condition where cell dies
					if (neighbors < 2 || neighbors > 3)
						changer_grid[x][y] = 1;
					
					//otherwise cell ives
				}
			}   //______________________________________________________________________________________________
		}


		//CHANGER
		for (int x = 0; x < GRID_HEIGHT; x++) {
			for (int y = 0; y < GRID_WIDTH; y++) {

				if (changer_grid[x][y] == 1) //condition where cell is to DIE
					grid[x][y] = 0;
				
				else if (changer_grid[x][y] == 2) //condition where cell is to LIVE
					grid[x][y] = 1;
			}
		}


		//PRINTER
		for (int x = 0; x < GRID_HEIGHT; x++) {
			for (int y = 0; y < GRID_WIDTH; y++){

				if (grid[x][y] == 1)
					printf("#");
				else
					printf(" ");
			}
				
			printf("\n");
		}
		
		
		
	}
	return 0;
}
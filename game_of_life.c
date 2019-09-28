
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//tentative
#define GRID_HEIGHT 3
#define GRID_WIDTH 10

int main(void) {
	
	//temporary just for testing
	bool grid[GRID_HEIGHT][GRID_WIDTH] = { { 0,0,0,1,1,0,1,0,0,1 }, { 0,1,0,1,1,1,0,1,1,1 }, { 1,1,1,1,1,0,0,0,0,0 } };
	
	//for printing initial grid
	for (int x = 0; x < GRID_HEIGHT; x++) {
		for (int y = 0; y < GRID_WIDTH; y++)
			printf("%d ", grid[x][y]);
			
		printf("\n");
	}
		
	
	return 0;
}
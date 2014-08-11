#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int PossibleSteps(int x, int y){
	if(x == 0 && y == 1){
		return 1;
	}
	if(x == 1 && y == 0){
		return 1;
	}
	if(x == 0){
		return PossibleSteps(x, y - 1);
	}
	if(y == 0){
		return PossibleSteps(x - 1, y);
	}
	if(x != 0 && y != 0){
		return PossibleSteps(x-1, y) + PossibleSteps(x, y-1);
	}
}

int main(int argc, char** argv){
	if(argc == 2 || argc == 1){
		printf("Missing arguments\n");
	}

	int result = 0;
	int target_x = 0;
	int target_y = 0;
	target_x = atoi(*(argv + 1));
	target_y = atoi(*(argv + 2));
	result = PossibleSteps(target_x, target_y);	
	printf("There are %d ways to get (%d,%d)\n", result, target_x, target_y);
	return 0;
}
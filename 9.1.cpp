#include <iostream>
#include <stdio.h>
#include <stdlib.h>
int floor[100];

int PossibleSteps(int target){

	if(target == 1){
		floor[1] = 1;
		return 1;
	}
	if(target == 2){
		floor[2] = 2;
		return 2;
	}
	if(target == 3){
		floor[3] == 3;
		return 3;
	}
	if(floor[target] != 0){
		return floor[target];
	}

	floor[target] = PossibleSteps(target - 1) + PossibleSteps(target - 2) + PossibleSteps(target - 3);
	return floor[target];
}


int main(int argc, char** argv){
	if(argc == 1){
		printf("missing argument");
	}
	int target = 0;
	target = atoi(*(argv+1));
	int result = PossibleSteps(target);
	printf("There are %d choices to finish %d floors.\n", result, target);
	return 0;
}
#include <stdio.h>
#include "maps.h"

const char *maps[2] = {"wilderness\n", "cave\n"}; 
int len = sizeof(maps) / sizeof(maps[0])


int mapControl(){
	int cmd;
	printf("1. Explore\n2. Return to Hut\n");
	scanf("%d", &cmd);

	return cmd;
}

void initiateExplore(int cmd){
	if (cmd == 1){ // wilderness 
		wild(mapControl());
	}
    	else if(cmd == 2){ // cave
		cave(mapControl());
	}
	else{
		printf("Area not discovered yet\n");
	}	
}

void wild(int mapCMD){
	printf("Your in the Wilderness\n");
	int choice = mapControl();

	if (mapCMD == 1){
		// combat
		printf("FIGHT!!")
	}
	else if (mapCMD == 2){
		// retreat
		printf("You're inside the hut\n");
	}

}

void cave(int mapCMD){
	printf("You're in the Spider's Cave\n");
	int choice = mapControl();

	if (mapCMD == 1){
		// combat
		printf("fightt!!");
	}
	else if(mapCMD == 2){
		// retreat
		printf("You're inside the hut\n");
	}
}

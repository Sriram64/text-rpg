#include <stdio.h>
#include <stdbool.h>
#include "maps.h"

struct Player{
    int pHP;
    int pDMG;
};

struct Enemy{
    int eHP;
    int eDMG;
};

/*
int playerHP = 100;
int enemyHP = 100;

int playerDMG = 50;
int enemyDMG = 25;
*/

struct Player player = {100, 50};


struct Enemy ogre = {100, 25};


struct Enemy spider = {200, 35};


int mapControl(){
	int cmd;
	printf("1. explore\n2. return to hut\n");
	scanf("%d", &cmd);

	return cmd;
}

void combat(int enemyHP, int enemyDMG){
    bool event = true;

    while(event){
        int cmd;
        printf("1. attack\n2. retreat\n");
        scanf("%d", &cmd);

        if (cmd == 1){
                enemyHP -= player.pHP;
                printf("enemey health: %d\n", enemyHP);

                if (enemyHP <= 0){
                        printf("The Ogre has been SLAINED!!!\n");
                        break;
                }

                printf("You've been attacked by the Ogre!!\n");
                player.pHP -= enemyDMG;
                printf("your health: %d\n", player.pHP);

		if (player.pHP <= 0){
			printf("YOU HAVE BEEN SLAINED!!!\n");
			break;
		}
        }

        else if(cmd == 2){
                printf("YOUS A PUSSY XD\n");
        }


    }
}

void wild(){
    //possible enemies - ogres

	printf("You're in the Wilderness!\n");
	int choice = mapControl();
	
	if (choice == 1){
		printf("A wild OGRE has appeared!!!\n");
		combat(ogre.eHP, ogre.eDMG);		
	}
	else if(choice == 2){
		printf("You're inside the hut\n");
	}
}

void cave(){
    //possible enemies - spiders

	printf("You're in the Spider's Cave\n");
	int choice = mapControl();

	if(choice == 1){
		printf("A poisounous SPIDER has appeared!!!\n");
		combat(spider.eHP, spider.eDMG);
	}
	else if(choice == 2){
		printf("You're inside the hut\n");
	}
}

int main(){
   
    int place;
    printf("1. wilderness\n2. cave\n");
    scanf("%d", &place);
    if (place == 1){
    	wild();
    }
    else if(place == 2){
    	cave();
    }
    else{
    	printf("Area not discovered yet\n");
    }

    return 0;
}


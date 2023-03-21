/* Library Definition */
#include <stdio.h>
#include <stdlib.h>

/* Pre-processor Directive Definition */
#define maxSize 8
#define towerNumber 3

/* Variables Definition */
int counter = 0;

/* Structure Definition */
struct hanoi{
		int diskNumber = 0;
		int startMove = 0;
		int finishMove = 0;
		int startMovement = 0;
		int finishMovement = 0;
		int moveCounter = 0;
		int towers[towerNumber][maxSize] = {{0},{0}};
		const int maxDisk = 8;
}hanoi;

/* Function Headers Definition */
void delay(void);
void toMove(void);
bool checkDiskNumber(void);
void initTower(void);
void displayTowers(void);
void consoleClear(void);
void selectMove(void);
void start(void);
bool controlProgram(void);
void completeProgram(void);

/* Main Function Definition */
int main(){
	
	/* Local Variables Definition */
	bool loopState = true;
	
	start(); // get the disk number
	initTower(); // determine disk arrangement

	while(loopState){
		
		displayTowers(); // display game menu
		selectMove(); // select next step move
		toMove(); // determine updated arrangement table with by selected step move
		loopState = controlProgram(); // to control game state
	}
	
	completeProgram(); // print score and finish the game
	
	return 0;
}

/* Function Bodies Definition */
bool checkDiskNumber(void){ // disk number checking
	
	if(hanoi.diskNumber < 3){
		printf("\n\n        Message;");
		printf("\n\n        Wrong Choice ! Your disk number must be higher than two.\n\n        ");
		for(counter=0; counter<50; counter++){
			printf("*");
			delay();
		}
		consoleClear();
		return false;
	}
	else{
		consoleClear();
		return true;
	}
}

void delay(void){
	
	/* Local Variable Definition */
	unsigned long int time;
	
	for(time=0; time<30000000; time++);
}

void selectMove(void){ // determine the next step move and check suitablity
	
	/* Local Variable Definition */
	bool startFlag = false;
	
	while(startFlag != true){
	consoleClear();
	displayTowers();
	printf("\n\n         Message;");
	printf("\n\n         Plase, select a move starting tower.");
	printf("\n\n         #1 TowerA		#2 TowerB		#3 TowerC");
	printf("\n\n         Tower Number #: ");
	scanf("%d", &hanoi.startMove);
	
	hanoi.startMove--;		

	if(hanoi.startMove > 2 ){
		printf("\n         Wrong Choice ! Your tower should be one between three.\n\n         ");
		for(counter=0; counter<50; counter++){
		printf("*");
		delay();
		}
		startFlag = false;
	}
	else{
		printf("\n\n         Plase, select a move finishing tower.");
		printf("\n\n         Tower Number #: ");
		scanf("%d", &hanoi.finishMove); 
		hanoi.finishMove--;
		if(hanoi.startMove == hanoi.finishMove){
			printf("\n         Wrong Choice ! Your tower moves should not be same.\n\n         ");
			for(counter=0; counter<50; counter++){
			printf("*");
			delay();
			}
			hanoi.finishMove = 0;
			consoleClear();
			startFlag = false;
		}
		else if(hanoi.towers[hanoi.startMove][0] != 0){
			startFlag = true;
		}
		else{
			printf("\n         Wrong Choice ! Your tower should be one between three.\n\n         ");
			for(counter=0; counter<50; counter++){
			printf("*");
			delay();
			}
			startFlag = false;	
			}
		}
	}
}

void start(void){ // get the disk number and check by functions
	
	/* Local Variable Definition */
	bool startFlag = false;
	
	while(startFlag != true){
	printf("\n\n        Welcome to the Honoi Game !");
	printf("\n\n        Plase, enter a disk number : ");
	scanf("%d", &hanoi.diskNumber);
	startFlag = checkDiskNumber();		
	}
}

void completeProgram(void){ // print the score
	
	consoleClear();
	displayTowers();
	printf("\n\n         Message;");
	printf("\n\n       	 Congrats !\n");
	printf("\n       	 Your Score : %d\n\n", hanoi.moveCounter);
}

void toMove(void){ // display updated table state 
	
	/* Local Variables Definition */
	int temporary = 0;
	counter = 0;
	
	if(hanoi.towers[hanoi.startMove][0] == 0){
		hanoi.startMovement = 0;
	}
	else{
		while(hanoi.towers[hanoi.startMove][counter] != 0){
			hanoi.startMovement = counter; 
			counter++;
		}
	}
	
	counter = 0;
	
	if(hanoi.towers[hanoi.finishMove][0] == 0){
		hanoi.finishMovement = 0;
	}
	else{
		while(hanoi.towers[hanoi.finishMove][counter] != 0){
			hanoi.finishMovement = counter; 
			counter++;
			}
		}
		
	if(hanoi.towers[hanoi.finishMove][hanoi.finishMovement] == 0){		
		temporary = hanoi.towers[hanoi.startMove][hanoi.startMovement];
		hanoi.towers[hanoi.startMove][hanoi.startMovement] = hanoi.towers[hanoi.finishMove][hanoi.finishMovement];
		hanoi.towers[hanoi.finishMove][hanoi.finishMovement] = temporary;	
		hanoi.moveCounter++;
	}
	else if(hanoi.towers[hanoi.finishMove][hanoi.finishMovement] > hanoi.towers[hanoi.startMove][hanoi.startMovement]){
		hanoi.finishMovement++;
		temporary = hanoi.towers[hanoi.startMove][hanoi.startMovement];
		hanoi.towers[hanoi.startMove][hanoi.startMovement] = hanoi.towers[hanoi.finishMove][hanoi.finishMovement];
		hanoi.towers[hanoi.finishMove][hanoi.finishMovement] = temporary; 
		hanoi.moveCounter++;
	}
	else{
			printf("\n         Your choice not suitable against the game rules.\n\n         ");
			for(counter=0; counter<50; counter++){
			printf("*");
			delay();
		}
	}						
}

void initTower(void){ // arrangement the disk
	
	/* Local Variables Definition */
	int tempNumber = hanoi.diskNumber; 
	
	for(counter=1; counter<hanoi.maxDisk+1; counter++){
		if(counter <= hanoi.diskNumber){
			hanoi.towers[0][counter-1] = (tempNumber);	
		}
		tempNumber--;
	}		
}

void consoleClear(void){
	system("cls");
}

void displayTowers(void){ // print the table
		
	printf("\n\n       	 ");
	
	for(counter=0; counter<hanoi.diskNumber; counter++){
		if(hanoi.towers[0][(hanoi.diskNumber-1)-counter] == 0){
		printf("|   |		", hanoi.towers[0][(hanoi.diskNumber-1)-counter]);	
		}
		else{
		printf("| %d |		", hanoi.towers[0][(hanoi.diskNumber-1)-counter]);	
		}
		
		if(hanoi.towers[1][(hanoi.diskNumber-1)-counter] == 0){
		printf("|   |		", hanoi.towers[1][(hanoi.diskNumber-1)-counter]);	
		}
		else{
		printf("| %d |		", hanoi.towers[1][(hanoi.diskNumber-1)-counter]);	
		}
		
		if(hanoi.towers[2][(hanoi.diskNumber-1)-counter] == 0){
		printf("|   |		", hanoi.towers[2][(hanoi.diskNumber-1)-counter]);	
		}
		else{
		printf("| %d |		", hanoi.towers[2][(hanoi.diskNumber-1)-counter]);	
		}
	
		printf("\n\n         ");		
		}
	
	printf("TowerA		TowerB		TowerC\n");	
}

bool controlProgram(void){ // to check game finishing state
	
	/* Local Variable Definition */
	bool status = false;
	
	for(counter=0; counter<hanoi.diskNumber; counter++){
		if(hanoi.towers[2][counter] == (hanoi.diskNumber-counter)){
				status = false;
		}
		else{
				status = true;
			}
		}
			
	return status;
}

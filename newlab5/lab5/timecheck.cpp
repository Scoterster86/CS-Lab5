#include "lab5.h"
int timecheck(){
	//initialize variables
//	int i, j, k, m, b, c, d;
	if (TIME % 25 == 0){
		cout<<"next enters store at time " <<TIME <<endl;
		/*
		for (m = 0; m <= 1; m++){
			if (m == 0){
				printf("\n FIRST FLOOR\n");
			}
			else{
				printf("\n SECOND FLOOR\n");
			}
			//runs loop until i=WIDTH
			for (i = -1; i <= WIDTH; i++){//start i for loop
				//initiates for loop for first and last iteration of i
				if (i == -1 || i == WIDTH){//start if1
					//creates the top/bottom border
					for (j = 0; j <= (LENGTH * 5); j++){//start j for loop
						//*5 to account for the 4 spaces allocated for the digit and a space
						if (j == LENGTH * 5){//start if2
							printf("-\n");
						}//end if2
						else{
							printf("-");
						}
					}//end j for loop
				}//end if1
				else{//begin else
					for (k = -1; k <= LENGTH; k++){//start k for loop
						//prints out the left border of the array
						if (k == -1){
							printf("|");
						}
						//prints out the current row of the array
						else if (0 <= k && k<LENGTH){
							printf("%4d ", Floor[i][k][m]);
						}
						//prints out the right border of the array
						else{
							printf("|\n");
						}
					}//end k for loop
				}//end else
			}//end i for loop
		}//end m for loop
		//fills the array Floor with 0s
		for (b = 0; b<LENGTH; b++){
			for (c = 0; c<WIDTH; c++){
				for (d = 0; d<HEIGHT; d++){
					Floor[b][c][d] = 0;
				}//end d for loop
			}//end c for loop
		}//end b for loop
		*/
	}//end if
	return 0;
}

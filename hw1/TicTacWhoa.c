#include <stdio.h>
#include <stdlib.h> 

/*global character array for the board*/
char board[3][3];

/*initializing empty spaces in the array*/
void boardinit() {
	int m, n;
	for(m=0; m < 3; m++) { 
		for(n=0; n < 3; n++) { 
			board[m][n] = ' ';
		}
	}
}

void hvh() { 
	printf("Human v. Human game started\n");
	int i, j, ct=0, win=0;
	char k, icon = 'X';  
	/*initializing the empty spaces in the array*/
/*	for(i=0; i < 3; i++) { 
		for(j=0; j < 3; j++) { 
			board[i][j] = ' ';
		}
	} */
	boardinit();
	while(ct < 9 && win == 0) { 
		for(i=0;i < 3; i++) { 
			printf("%c%c|%c|%c", 'C'-i, board[i][0], board[i][1], board[i][2]);
			if (i != 2) {
				printf("\n -----\n");
			}
		}
		printf("\n 1 2 3 \n");
		if(ct % 2 == 0) { 
			icon = 'X';
		} else { 
			icon = 'O';
		}
		printf("Player %c, please choose your move: _", icon); 
		scanf(" %c%d", &k, &j);
		printf("Player %c chose %c%d\n", icon, k, j);
		if (k == 'C') { 
			i = 1;
		} else if (k == 'B') {
			i = 2;
		} else if (k == 'A') { 
			i = 3; 
		} 
		board[i-1][j-1] = icon;
		/*win condition for rows*/
		for(i = 0; i < 3; i++) { 
			if(board[i][0] != ' ' && board[i][1] != ' ' && board[i][2] != ' ') { 
				if(board[i][0]==board[i][1] && board[i][0]==board[i][2]) {
					for(i=0;i < 3; i++) { 
						printf("%c%c|%c|%c", 'C'-i, board[i][0], board[i][1], board[i][2]);
						if (i != 2) {
							printf("\n -----\n");
						}
					}
					printf("\n 1 2 3\n");
					printf("\nPlayer %c wins!\n", icon);
					win++;
				}
			}
		}
		/*win condition for columns*/	
		for(i=0; i < 3; i++) {
			if(board[0][i] != ' ' && board[1][i] != ' ' && board[2][i] != ' ') { 
				if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) { 
					for(i=0;i < 3; i++) { 
						printf("%c%c|%c|%c", 'C'-i, board[i][0], board[i][1], board[i][2]);
						if (i != 2) {
							printf("\n -----\n");
						}
					}
					printf("\n 1 2 3\n");	
					printf("Player %c wins!\n", icon);
					win++;
				}
			} 		
		}
		/*win condition for diagonals*/
		for(i=0; i<1; i++) {
			if(board[i][i] != ' ') { 
				if(board[i][i] == board[i+1][i+1] && board[i][i] == board[i+2][i+2]) { 
					for(i=0;i < 3; i++) { 
						printf("%c%c|%c|%c", 'C'-i, board[i][0], board[i][1], board[i][2]);
						if (i != 2) {
							printf("\n -----\n");
						}
					}
					printf("\n 1 2 3\n");
					printf("\nPlayer %c wins!\n",icon);
					win++;
				}
			}
		}
		ct++;
		if(ct == 9 && win == 0) { 
			for(i=0;i < 3; i++) { 
				printf("%c%c|%c|%c", 'C'-i, board[i][0], board[i][1], board[i][2]);
				if (i != 2) {
				printf("\n -----\n");
				}
			}
			printf("\n 1 2 3\n");
			printf("The game is a tie!\n");
		}
	}
 
}

void hvc () {}



int main(void) { 
	char opt;
	while(opt != '4') {
		printf("Welcome to Secure-Tic-Tac-Whoa!\n");
		printf("1. Start New Game (Human v. Human)\n");
		printf("2. Start New Game (Human v. AI)\n");
		printf("3. Game Settings\n");
		printf("4. Exit Game\n");
		printf("Choose Option: _");
		scanf("%s", &opt);
		switch(opt) { 
			case '1' : 
				hvh();
			case '2' : 
				hvc();
		}
	}
	return 0;
}








#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**************************
 *Name: Akhil Pappu 
 *Date: 17 January 2020
 *Project 1: Tic Tac Whoa
 *EECS 22, Professor QV Dang
 **************************/

/*color codes*/
char RED[] =  "\x1b[31m";
char END[] = "\x1b[m";
char GREEN[] = "\x1b[32m";
char WHITE[] = "";

/*global variables*/
char board[3][3];
char icon; int win;
char s1 = 'X', s2 = 'O';  
char c1[8], c1e[8], c2[8], c2e[8], store1[8], store2[8];
char color1[] = "white", color2[] = "white";
int ct = 0;

/*initializing empty spaces in the array*/
void boardinit() {
	int m, n;
	for(m=0; m < 3; m++) { 
		for(n=0; n < 3; n++) { 
			board[m][n] = ' ';
		}
	}
}

/*printing out the board*/
void printboard() { 
	int i, j;
	for(i=0;i<3;i++) { 
		printf("%c ", 'C'-i);
			for(j=0;j<3;j++){
				if(board[i][j] == s1) { 
					printf("%s%c%s", c1, board[i][j], c1e);
				}
				if(board[i][j] == s2) { 
					printf("%s%c%s", c2, board[i][j], c2e);
				}
				if(board[i][j] == ' ') { 
					printf("%c", board[i][j]);
				}
				if(j != 2) { 
					printf("|");
				}
			}	
		if(i != 2){ 
			printf("\n  -----\n");
		}	
	}
		printf("\n  1 2 3\n"); 
}
			
/*checking win conditions*/
void wincondition() {
	int i;
	/*win condition for rows*/
	for(i = 0; i < 3; i++) { 
		if(board[i][0] != ' ' && board[i][1] != ' ' && board[i][2] != ' ') { 
			if(board[i][0]==board[i][1] && board[i][0]==board[i][2]) {
				printboard();
				printf("Player %c wins!\n\n", icon);
				win++;
			}
		}
	}
	/*win condition for columns*/
	for(i=0; i < 3; i++) {
		if(board[0][i] != ' ' && board[1][i] != ' ' && board[2][i] != ' ') { 
			if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) { 
				printboard();		
				printf("Player %c wins!\n\n", icon);
				win++;
			}
		} 		
	}
	/*win condition for diagonals (L --> R)*/
	for(i=0; i<1; i++) {
		if(board[i][i] != ' ') { 
			if(board[i][i] == board[i+1][i+1] && board[i][i] == board[i+2][i+2]) { 
				printboard();	
				printf("Player %c wins!\n\n",icon);
				win++;
			}
		}
	}
	/*win condition for diagonals (R --> L)*/
	if(board[0][2] != ' ' && board[1][1] != 0 && board[2][0] != 0) {
		if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) { 
			printboard();
			printf("Player %c wins!\n\n", icon);
			win++;
		}
	}
}

/*getting computer move*/
void computermove() {
	int i, j, upd = 0;
	char d;
	for(i=0; i < 3; i++) { 
		for(j=0; j < 3; j++) { 
			if(board[i][j] == ' ') { 
				while(upd == 0) {	
					board[i][j] = icon;
				 	if(i == 0) { 
						d = 'C';
					} if(i == 1) { 
						d = 'B';
					} if(i == 2) { 
						d = 'A';
					} 
					printf("Player %c (AI) chose %c%d\n", icon, d, j+1);
					upd++;
				}
			}
		}
	} 
}

/*getting player move*/
void playermove() {
	int i, j;
	char k;
	printf("Player %c, please choose your move: ", icon); 
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
}

/*settings function to change icon or color*/
void settings() {
	char yn, ny, sel1, sel2;
	printf("Current icon for Player 1 is %c. Current icon for Player 2 is %c.\n", s1, s2);
	printf("Would you like to change the icon you are using? (Y/N) "); 
	scanf(" %c", &yn);
	if(yn == 'Y') {
		printf("What icon do you want to use to represent Player 1? "); 
		scanf(" %c", &s1);
		printf("What icon do you want to use to represent Player 2? ");
		scanf(" %c", &s2);
	} 
	printf("Current color for Player 1 is %s. Current color for Player 2 is %s.\n", color1, color2);
	printf("Would you like to change the icon color? (Y/N) ");  
	scanf(" %c", &ny); 
	if(ny == 'Y') { 
		printf("What color would you like to represent Player 1? (R)ed/(G)reen/(W)hite: ");  
		scanf(" %c", &sel1);
		if(sel1 == 'R') { 
			strcpy(store1, RED);
			strcpy(c1e, END);
			strcpy(color1, "red"); 
		} else if(sel1 == 'G') { 
			strcpy(store1, GREEN);
			strcpy(c1e, END);
			strcpy(color1, "green");
		} else if(sel1 == 'W') { 
			strcpy(store1, WHITE);
			strcpy(c1e, END);
			strcpy(color1, "white");
		}
		printf("What color would you like to represent Player 2? (R)ed/(G)reen/(W)hite: ");
		scanf(" %c", &sel2);
		if(sel2 == 'R') {
			strcpy(store2, RED);
			strcpy(c2e, END);
			strcpy(color2, "red");
		} else if(sel2 == 'G') { 
			strcpy(store2, GREEN);
			strcpy(c2e, END);
			strcpy(color2, "green");
		} else if(sel2 == 'W') { 
			strcpy(store2, WHITE);
			strcpy(c2e, END);
			strcpy(color2, "white");
		}
	}
}

/*human vs human function*/
void hvh() { 
	printf("Human v. Human game started\n");
	ct=0;
	boardinit();
	while(ct < 9 && win == 0) { 
		printboard();
		if(ct % 2 == 0) { 
			icon = s1;
			strcpy(c1,store1);
		} else { 
			icon = s2;
			strcpy(c2, store2);
		}
		playermove();	
		wincondition(); 		
		ct++;
		if(ct == 9 && win == 0) { 
			printf("The game is a tie!\n\n");
		}
	}
 
}

/*human vs AI function*/
void hvc () {
	int player, ct=0;
	printf("Human v. AI game started\n");
	boardinit(); 
	printf("Would you like to be Player 1 or Player 2? ");
	scanf("%d", &player);
	if(player == 1) { 
		while(ct < 9 && win == 0) { 
			printboard();
			if(ct%2 == 0) {
				strcpy(c1, store1);  
				icon = s1;
				playermove();
			} else {
				strcpy(c2, store2);
				icon = s2;
				computermove();
			}
			wincondition();
			ct++;
			if(ct == 9 && win == 0) { 
				printboard();	
				printf("The game is a tie!\n");	 	
			}
		}
	} else {
		while(ct < 9 && win == 0) {	
			printboard();
			if(ct%2==0) { 
				strcpy(c1, store1);
				icon = s1;
				computermove();
			}else { 
				strcpy(c2, store2);
				icon = s2;
				playermove();
			}
			wincondition();
			ct++;
			if(ct == 9 && win == 0) { 
				printboard();	
				printf("The game is a tie!\n");
			}
		}
	}
}

/*start of main*/
int main(void) { 
	char opt;
	while(opt != '4') {
		win = 0;
		printf("Welcome to Secure-Tic-Tac-Whoa!\n");
		printf("1. Start New Game (Human v. Human)\n");
		printf("2. Start New Game (Human v. AI)\n");
		printf("3. Game Settings\n");
		printf("4. Exit Game\n");
		printf("Choose Option: ");
		scanf("%s", &opt);
		printf("\n");
		switch(opt) { 
			case '1' : 
				hvh();
				break;
			case '2' : 
				hvc();
				break;
			case '3' : 
				settings();
				break;
		}
	}
	return 0;
}
/*EOF*/




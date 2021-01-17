#include <stdio.h> 
char board[3][3];

void boardinit() { 
	int i, j; 
	for(i =0;i<3;i++) {
		for(j=0;j<3;j++){
			board[i][j] = ' ';
		}
	}
}
/*void printboard() {
	int i, j;
	for(i=0;i < 3; i++) {
		printf("%c", board[i][j]);
		printf("|");
	for(j=0;j<3;i++) {

		printf("%c", board[i][j]);
		printf("|");
		printf("%c", board[i][1]);
		printf("|");
		printf("%c", board[i][2]);
		if(i != 2){ 
		printf("\n-----\n");
}
		printf("\n 1 2 3\n");
}
 		printf("\n 1 2 3\n");
}*/

int main() { 
	boardinit();
	int i, j;
	for(i=0;i<3;i++) { 
		for(j=0;j<3;j++){
			printf("%c", board[i][j]);
			if(j != 2) { 
				printf("|");
			}
		}
		if(i != 2){ 
			printf("\n------\n");
		}
	}
		printf("\n 1 2 3\n");
}







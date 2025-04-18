#include <stdio.h>
#include <stdlib.h>

//function prototype
void DisplayBoard(char Board[3][3]);
int WinCheck(char Board[3][3]);
void RunGame(char Board[3][3]);


void DisplayBoard(char Board[3][3]){
  for(int i=0;i<3;i++) {
      for(int j=0;j<3;j++) {
          printf("%c",Board[i][j]);
      }
      printf("\n");

  }


}

int WinCheck(char Board[3][3]) {
    // Checking rows
    for (int i = 0; i < 3; i++) {
        if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][0] != '_') {
            printf("Player %c wins!\n", Board[i][0]);
            return 1;  // Game over
        }
    }

    // Checking columns
    for (int j = 0; j < 3; j++) {
        if (Board[0][j] == Board[1][j] && Board[1][j] == Board[2][j] && Board[0][j] != '_') {
            printf("Player %c wins!\n", Board[0][j]);
            return 1;  // Game over
        }
    }

    // Anti-diagonal
    if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0] && Board[0][2] != '_') {
        printf("Player %c wins!\n", Board[0][2]);
        return 1;  // Game over
    }

    // Main diagonal
    if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[0][0] != '_') {
        printf("Player %c wins!\n", Board[0][0]);
        return 1;  // Game over
    }

    // to check if the board is full but no winners aka a tie
    int IsFull =1;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if (Board[i][j] == '_') {
                IsFull = 0;
                break;
            }
        }
    }
    if (IsFull) {
        printf("It's a draw!\n");
        return 2;
    }

    return 0;  // No winner yet
}




void RunGame(char Board[3][3]){
    // to determine which players turns and to determine the position of where the user wants to put their piece
    int Run =0;
    int PositionX,PositionY;

    while (!Run) {
        printf("hello player 1, Please enter a x coordinate position");
        scanf("%d",&PositionX);

        printf("Please enter a y coordinate position");
        scanf("%d",&PositionY);

        if (Board[PositionX-1][PositionY-1] == 'X' || Board[PositionX-1][PositionY-1] == 'O') {
            printf("that zone is populated pick another");
            continue;
        }

        // now need to populate somewhere in the array
        Board[PositionX-1][PositionY-1]='X';
        DisplayBoard(Board);

        if (WinCheck(Board) ==1 ) {
            exit(0);
        }

        Run = 1;
    }

    while(Run) {
        printf("hello player 2, Please enter a x coordinate position");
        scanf("%d",&PositionX);

        printf("Please enter a y coordinate position");
        scanf("%d",&PositionY);

        if (Board[PositionX-1][PositionY-1] == 'X' || Board[PositionX-1][PositionY-1] == 'O') {
            printf("that zone is populated pick another");
            continue;
        }

        Board[PositionX-1][PositionY-1]='O';
        DisplayBoard(Board);

        if (WinCheck(Board) == 1 || WinCheck(Board) == 2) {
            exit(0);
        }



        RunGame(Board);
    }

}

int main(){
     //creates the base board that is empty and unpopulated
    char Board[3][3]= {
        {'_','_','_'},
        {'_','_','_'},
        {'_','_','_'}
    };
    printf("Welcome to tic,tac,toe\n");
        RunGame(Board);
    return 0;
}




/*
tic-tac-toe:
allow two players
a 3x3 board - 2d matrix
to populate a section of the board
win conditions check
 */
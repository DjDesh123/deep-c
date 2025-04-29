#include <stdio.h>
#include <stdlib.h>

// what i need to do is first create an if statmenet to check if the numbers the user enters are out of range
//then to improve the loop by removing certain parts of it and making it flow simplier
// do a better write up on parts of the project explain how the y work






//function prototype
void DisplayBoard(char *Board);
int WinCheck(char *Board);
void RunGame(char *Board);


void DisplayBoard(char *Board){
  for(int i=0;i<3;i++) {
      for(int j=0;j<3;j++) {
          printf("%c", *(Board+i*3+j));
      }
      printf("\n");

  }


}

int WinCheck(char *Board) {
    // Checking rows
    for (int i = 0; i < 3; i++) {
      if (*(Board+i*3+0) == *(Board+i*3+1) &&
         *(Board+i*3+1) == *(Board+i*3+2) &&
         *(Board+i*3+0) != '_'){

          printf("Player %c wins!\n", *(Board+i*3+0));
          return 1;
      }
    }


    // Checking columns
    for (int j = 0; j < 3; j++) {
        if (*(Board+0*3+j) == *(Board+1*3+j) &&
           *(Board+1*3+j) == *(Board+2*3+j) &&
           *(Board+0*3+j) != '_') {

          printf("Player %c wins!\n", (*Board+0*3+j));
            return 1;  // Game over
        }
    }

    // Anti-diagonal
    if (*(Board + 0*3 + 2) == *(Board + 1*3 + 1) &&
    *(Board + 1*3 + 1) == *(Board + 2*3 + 0) &&
    *(Board + 0*3 + 2) != '_') {

        printf("Player %c wins!\n", *(Board + 0*3 + 2));
        return 1;
    }

    // Main diagonal
    if (*(Board + 0*3 + 0) == *(Board + 1*3 + 1) &&
    *(Board + 1*3 + 1) == *(Board + 2*3 + 2) &&
    *(Board + 0*3 + 0) != '_') {

        printf("Player %c wins!\n", *(Board + 0*3 + 0));
        return 1;
    }


    // to check if the board is full but no winners aka a tie
    int IsFull = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (*(Board + i*3 + j) == '_') {
                IsFull = 0;
                break;
            }
        }
    }

    if (IsFull) {
        printf("It's a draw!\n");
        return 2;
    }
    // No winner yet
    return 0;
}




void RunGame(char *Board){
    // to determine which players turns and to determine the position of where the user wants to put their piece
    int Run =0;
    int PositionX,PositionY;

    while (!Run) {
        printf("hello player 1, Please enter a x coordinate position");
        scanf("%d",&PositionX);

        printf("Please enter a y coordinate position");
        scanf("%d",&PositionY);

        // to handle the index being at 0
        PositionX--;
        PositionY--;

        // to check through the 2D array to see if the position is populated
        if (*(Board + PositionX * 3+ PositionY) != '_') {
          printf("that zone is populated pick another");
          continue;
        }

        /* now need to populate somewhere in the array
           the way that this works is when you use a 2d array with a pointer it travels througyh memory addresses
           this means that you have add the posiiton via flat memory
           the equationt go from [0][0] to [1][0] you need to do is
           *(Board+PositionXx*Coulms+PositionY)
        */
        *(Board+PositionX*3+PositionY)='X';
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

        PositionX--;
        PositionY--;

        if(*(Board+PositionX*3+PositionY) != '_'){
            printf("that zone is populated pick another");
            continue;
        }


        *(Board+PositionX*3+PositionY) = 'O';
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
        RunGame(&Board[0][0]);
    return 0;
}




/*
tic-tac-toe:
allow two players
a 3x3 board - 2d matrix
to populate a section of the board
win conditions check
 */
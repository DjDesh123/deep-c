#include <stdio.h>
#include <stdlib.h>

// constants
#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4
#define EXIT 5

// function prototypes
int addition(int UserInput1, int UserInput2);
int subtraction(int UserInput1, int UserInput2);
int multiply(int UserInput1, int UserInput2);
int divide(int UserInput1, int UserInput2);

// for adding
int addition(int UserInput1,int UserInput2) {
    return UserInput1 + UserInput2;
}

// for subtracting
int subtraction(int UserInput1,int UserInput2) {
    return UserInput1 - UserInput2;
}

// for multiplying
int multiply(int UserInput1,int UserInput2) {
    return UserInput1 * UserInput2;
}

// for dividing
int divide(int UserInput1,int UserInput2) {
    return UserInput1 /UserInput2;
}

// main function
int main() {

    int UserChoice , UserInput1 , UserInput2;

    printf("please enter a number");
    scanf("%d", &UserInput1);

    printf("please enter a number");
    scanf("%d", &UserInput2);


    // loops until the user enters a valid choice that's in range of the options
     do {
         // Asks the user to enter which maths operation
         printf("1. Add\n");
         printf("2. Subtract\n");
         printf("3. Multiply\n");
         printf("4. Divide\n");
         printf("5. Exit\n");

         printf("please enter your choice: ");
         scanf("%d", &UserChoice);

         switch (UserChoice) {
             case ADD:
                 printf("Addition: %d\n", addition(UserInput1, UserInput2));
             case SUB:
                 printf("Subtraction: %d\n", subtraction(UserInput1,UserInput2));
             case MUL:
                 printf("Multiplication: %d\n", multiply(UserInput1, UserInput2));
             case DIV:
                 printf("Division: %d\n", divide(UserInput1, UserInput2));
             case EXIT:
                 exit(0);
             default:
                 printf("Wrong choice\n");
         }
     } while (UserChoice < ADD || UserChoice > EXIT);
}

// change these to floats to handle decimal points
#include <stdio.h>
#include <stdlib.h>

// constants
#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4
#define EXIT 5

// function prototypes
float addition(int UserInput1, int UserInput2);
float subtraction(int UserInput1, int UserInput2);
float multiply(int UserInput1, int UserInput2);
float divide(int UserInput1, int UserInput2);

// for adding
float addition(int UserInput1,int UserInput2) {
    return UserInput1 + UserInput2;
}

// for subtracting
float subtraction(int UserInput1,int UserInput2) {
    return UserInput1 - UserInput2;
}

// for multiplying
float multiply(int UserInput1,int UserInput2) {
    return UserInput1 * UserInput2;
}

// for dividing
float divide(int UserInput1,int UserInput2) {
    return UserInput1 /UserInput2;
}

// main function
int main() {

    int UserChoice;
    float UserInput1 , UserInput2;

    printf("please enter a number");
    scanf("%f", &UserInput1);

    printf("please enter a number");
    scanf("%f", &UserInput2);


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
                 printf("Addition: %f\n", addition(UserInput1, UserInput2));
             case SUB:
                 printf("Subtraction: %f\n", subtraction(UserInput1,UserInput2));
             case MUL:
                 printf("Multiplication: %f\n", multiply(UserInput1, UserInput2));
             case DIV:
                 printf("Division: %f\n", divide(UserInput1, UserInput2));
             case EXIT:
                 exit(0);
             default:
                 printf("Wrong choice\n");
         }
     } while (UserChoice < ADD || UserChoice > EXIT);
}

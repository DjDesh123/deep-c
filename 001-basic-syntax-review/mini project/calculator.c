#include <stdio.h>
#include <stdlib.h>

// constants
#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4
#define EXIT 5

// function prototypes
float addition(float UserInput1, float UserInput2);
float subtraction(float UserInput1, float UserInput2);
float multiply(float UserInput1, float UserInput2);
float divide(float UserInput1, float UserInput2);
void clearBuffer();


void clearBuffer() {
    // Clear invalid input
    while (getchar() != '\n');
}


// for adding
float addition(float UserInput1,float UserInput2) {
    return UserInput1 + UserInput2;
}

// for subtracting
float subtraction(float UserInput1,float UserInput2) {
    return UserInput1 - UserInput2;
}

// for multiplying
float multiply(float UserInput1,float UserInput2) {
    return UserInput1 * UserInput2;
}

// for dividing
float divide(float UserInput1,float UserInput2) {
    return UserInput1 /UserInput2;
}

// main function
int main() {

    int UserChoice;
    float UserInput1 , UserInput2;
    int InputStatus=0;

    // To loop until the user enters two valid inputs
    do {
        // uses one scanf for tidier code
        printf("Enter two numbers: ");

        InputStatus=scanf("%f %f",&UserInput1,&UserInput2);

        // to check if two floats have been inputted
        if (InputStatus!= 2) {
            printf("ERROR: must input a float numbers\n");
            clearBuffer();
        }

    }while (InputStatus != 2);



    // loops until the user enters a valid choice that's in range of the options
     do {

         printf("---Calculator options---\n");
         printf("1. Add\n");
         printf("2. Subtract\n");
         printf("3. Multiply\n");
         printf("4. Divide\n");
         printf("5. Exit\n");

         // Asks the user to enter which maths operation
         printf("please enter your choice: ");
         scanf("%d", &UserChoice);

         switch (UserChoice) {
             case ADD:
                 printf("Addition: %f\n", addition(UserInput1, UserInput2));
                 break;
             case SUB:
                 printf("Subtraction: %f\n", subtraction(UserInput1,UserInput2));
                 break;
             case MUL:
                 printf("Multiplication: %f\n", multiply(UserInput1, UserInput2));
                 break;
             case DIV:
                 printf("Division: %f\n", divide(UserInput1, UserInput2));
                 break;
             case EXIT:
                 exit(0);
             default:
                 printf("ERROR: invalid choice! Must be a number in range (1-5)\n");
         }
     } while (UserChoice < ADD || UserChoice > EXIT);
}


# Functions

Functions are a key part of any programming language which basically splits up the code into sections to improve readability and also to imporve the reuseabilty as well 

---

## C Function

```c

// Function declaration (prototype)
int add(int a, int b);

int main() {
    int num1 = 5, num2 = 7;
    int result;

    // Function call
    result = add(num1, num2);

    // Output the result
    printf("The sum is: %d\n", result);

    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}

```
As shown in this block of code functions can be created similar to main by giving the function a data type, a name and also potenially some parameters.
As well as this you can see a function prototype which is used to tell the compiler that these classes exists and whats the parameters are for them which improves speed

---

## C Function Parameters

A function parameters are variables that can be passed from one function to another even if they are local. When using parameters in your function you must declare the data type inside.

---

## C Scope

The word local and global are actually scopes in programming which are to say if a variable is able to be accessed all around the code or in a select function.

---

## C Function Declaration

you can declare a function via the prototype as mentioned. this is a very foundational skill every programmer should know about 

---

## C Recursion 
C function recursion is when you loop a function by calling it inside itself to loop back at the start of the function this can be useful in certain cases like this:
```c
#include <stdio.h>

// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0) {
        return 1; // Base case
    } else {
        return n * factorial(n - 1); // Recursive call
    }
}

int main() {
    int number = 5;
    int result = factorial(number);
    
    printf("Factorial of %d is %d\n", number, result);
    
    return 0;
}
```
---
## Mini project

no mini project for this topic as we already can see that i know how to use a class 
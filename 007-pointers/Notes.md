# Pointers

---

## What is a Pointer?
A pointer stores the address of another variable.instead of working with the actual value you're working with the location where its stored.
This gives you direct access to memory which is crucial for dynamic memory, function parameter maniuplation, effucebt data stryctyres and system level and embedded programming
an example of this is shown underneath of what a pointer is and does.
```c
int x = 10;
int *p = &x;  // 'p' holds the address of 'x'
```
---

## Pointer Syntax
```c
int *ptr;     // Declares a pointer to int
ptr = &x;     // Assigns address of x to ptr
```
What the example above is doing is  that int *ptr is telling the compiler that ptf is a variable that is stored with the address pointer to an integer
then ptr is uses &x to get the memory address of x.
Why this matters is to understnad the difference between *(dereferencing ) and & (address of ) is key to understanding how C handles memory.
---

## Dereferencing a Pointer
```c
int x = 42;
int *p = &x;
printf("%d\n", *p); // Outputs: 42
```
what happens when we dereferencing a pointer is  that p holds the memory location of x and *p means "go to the address inside p and get the value"
this is importnant because it shows how we access and manipulate variavbles indirectly-super powerful in functions and data structures.
---

## pointer and memory address example
```c
#include <stdio.h>

int main() {
    int a = 5;
    int *ptr = &a;

    printf("Value of a: %d\n", a);
    printf("Address of a: %p\n", &a);
    printf("Pointer ptr points to: %p\n", ptr);
    printf("Value at ptr (dereferencing): %d\n", *ptr);

    return 0;
}
```
This is a wat to see how the memory address and pointer are effected when you point at another integer.
As you can see you can access the value of a and then address of a by using &a
Using %p you cab see were your pointer is pointing to 
and if you use the correct placeholder you can also see the value of ptr.
---

## Changing values with Pointers
```c
int a = 10;
int *ptr = &a;
*ptr = 20;  // Now a becomes 20
```
changes the value of the variables without directly referencing it. We would normally use this to modify a variable from another function (pass by reference) or used heavily in sorting algorithms (swapping values). 

---

## Pointers with different data types
```c
float f = 3.14;
float *fptr = &f;

char c = 'A';
char *cptr = &c;
```
This is useful as  the pointer type must match the vasriables type it points to 

---

## null pointers
```c
int *ptr = NULL;
```
The purpose of this is the pointer is not pointing and anything valid yet. You should always initialize pointers to null if they dont points to something. Accessioning an uninitialized pointer is undefined behaviour.

---

## pointer to pointer
```c
int a = 10;
int *p = &a;
int **pp = &p;

printf("%d\n", **pp); // Outputs 10
```
This allows you to work with multiple levels of indirection.
which in the real world the usage of this would be like a 2d array with malloc, double pointers in functions arguemnts for modifying memory blocks and managing arrays of strings ( char **argv in main)
---

## pointer arithmetic
```c
int arr[3] = {1, 2, 3};
int *p = arr;

printf("%d\n", *p);     // 1
p++;
printf("%d\n", *p);     // 2
```
increment the pointer to the next memory location(depending on data type size)
this example is if you use int*p it moves 3 bytes forward
but if it was char *p p~++ moves on byte.

iterating through arrays
managing buffers and memory regions efficiently


---

## arrays and pointer
```c
int arr[] = {1, 2, 3};
int *p = arr;

printf("%d\n", *(p + 1)); // 2
```
Arrays in C decay to pointers when they are passed to functions thats why p[i] and *(p+i) are the same which canbe used for efficent array traversal or simipler dynamic array handling.

---

## pointers in functions
```c
void update(int *n) {
    *n = 20;
}

int main() {
    int x = 10;
    update(&x);
    printf("%d", x); // Outputs 20
}
```
We pass a pointer to the variavke. inside the function we moidify the original variable value.
this can be used for swapping two variables and changing a variable inside a function without ising gloabal variables.

---

## fucntion pointers
```c
void greet() {
    printf("Hello!");
}

void (*fp)() = greet;
fp();  // Calls greet()
```
Allow us too store a function address and call it like a regular function.
this can be used for callback functions and function tables for dynamic behavior (like in OS kernels)
As well as this command pattern in structured programming 

# Strings 

strings are used for string text/characters. This can be used in a magnitude of ways like storing names or in comparisons etc.
Today we will be going through all the important ways to function with your code. 

---

## String basics
There are a fair few things you need to know when dealing with strings.
for example strings are an array of character which also ***Terminated by a null character (\0)***
Unlike other languages, strings in C are not a built-in data type.

---

### Declaring a string 
Now you must be wondering what that would look like:
```c
// exmaple of a string with fixed size
// A string with the space for 19 characters and the null character '\0'
char str[20];
```
Alternatively, you can use a pointer to create a string:
```c
// pointer to the string literal
// we will be going through pointer next week 
// its okay if you dont get it just yet 
char *str = "Hello World";
```

---

### Initializing strings
you can do this in two different ways by directly or using a string function 
```c
// initializing a string with a value
//automatically null-terminated
char str[30] = "Hello";
```
or alternatively:
```c
// using strcpy() (aka string copy)
strcpy(str,"Hello World!");
```
It's very important that the string array is large enough to hold characters ***and*** the null terminator.

---

## String length 
Use ***strlen()*** function to find length of a string. it excludes the null terminator so you'll get the amount of characters
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello";
    printf("Length of string: %lu\n", strlen(str));  // Outputs 5
    return 0;
}

```

---
## String access (indexing)
In c string are accessed by indexing into the array therefore the first characters index is 0 and the last one is length -1 as the final character is the terminator.
an example of this is:
```c
#include <stdio.h>

int main() {
    char str[] = "Hello";
    printf("First character: %c\n", str[0]);  // H
    printf("Last character: %c\n", str[4]);  // o
    return 0;
}
```
---

## String iteration
As well as this you can loop through the array. by using a for loop or a pointer
They would look like this:
```c
char str[] = "Hello";

// Using index
for (int i = 0; str[i] != '\0'; i++) {
    printf("%c ", str[i]);
}
printf("\n");

```
With a pointer:
```c
char *ptr = str;
while (*ptr != '\0') {
    printf("%c ", *ptr);
    ptr++;
}
```
---

## String concatenation
use ***strcat()*** top concatenate two strings 
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello";
    char str2[] = " World";
    strcat(str1, str2);  // Concatenates str2 to str1
    printf("Concatenated string: %s\n", str1);  // Outputs "Hello World"
    return 0;
}

```
***Important*** to make sure that the designation string so in this case str1 has enough space to hold the result of the concatenation.

---

## string comparison
Use ***strcmp()*** to compare two string like this:
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "World";
    
    if (strcmp(str1, str2) == 0) {
        printf("Strings are equal.\n");
    } else {
        printf("Strings are not equal.\n");  // Outputs this because strings are different
    }

    return 0;
}
```
A good note to take is the returns of strcmp
If 0 then the strings are equal
if it's a negative then the first string is lexicographically (in dictionary order) smaller
if it's a positive then the first string is lexicographically larger.

---

## copying string
use strcpy() to copy one string to another.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20];
    strcpy(str1, "Hello, World!");  // Copies string into str1
    printf("Copied string: %s\n", str1);
    return 0;
}
```

---

## String Tokenization
Use ***strtok()*** to split (a string into tokens delimited by a specific character)
This means you need a delimit to split the words apart and an example of this is:
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "apple,banana,orange";
    char *token = strtok(str, ",");  // Split by comma

    while (token != NULL) {
        printf("%s\n", token);  // Outputs each fruit on a new line
        token = strtok(NULL, ",");
    }
    
    return 0;
}
```

---

## Null terminators
In C, strings are always null-terminated.This means that the last character in a string must be \0 which signifies the end of the string,
An example of this:
```c
#include <stdio.h>

int main() {
    char str[] = "Hello";
    printf("Last character: %c\n", str[5]);  // Should be '\0' (null terminator)
    return 0;
}

```

---

## mini project
Instead of writing a project the plan is to use this knowledge to maybe tackle some leetcode questions.

---
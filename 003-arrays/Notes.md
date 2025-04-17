# arrays

## Introduction
Arrays are used to store multiple values in a single variable ,instead of declaring separate variables for each value.

---

## 1D arrays
An array that can be indexed as though it was a single line regardless of the number of dimensions it actually has.

---

### Declaration and Initialization
To create an array you first need to define the data type (like int) abd specify the name of the array followed by square brackets.
To insert values to it , use a comma-separated list inside curly braces, and make sure all values are of the same data type.
An example of this is :
```c
int MyArray[]={25,50,75,100};
```
However if you wanted to define the size of the array and the amount of elements that can be inside you would write
```c
int MyArray[5];

```
Putting the number inside the square brackets determine the size of the array.

---

### Memory Layout of 1D Arrays
In C, a 1D array is stored in contiguous memory locations.This means all elements of the array are laid out one after the other in memory.
From the previous example if we have 4 integers in our array and if int is 4 bytes in our system the array will take up 16 bytes as 4*4=16.
This can also be layed out in a table such as this one
```
| **Index** | **Value** | **Address (Assume base = 0x1000)** |
|:---------:|:---------:|:----------------------------------:|
| 0         | 10        | 0x1000                             |
| 1         | 20        | 0x1004                             |
| 2         | 30        | 0x1008                             |
| 3         | 40        | 0x100C                             |
| 4         | 50        | 0x1010                             |
```
As you can see the address are 4 bytes apart (for an int) because thats the size of one element.

---

### Input and Output
If you wish to input an element in the array you can replace or add it to the end of the array if the array size is larger than the number of elements in the array.
The reason of this is becasue arrays in c are fixed size so you can not append automatically like you can do in higher languages.
An example of appending to an array is by this:
```c
int arr[4] = {10, 20, 30};  // Array of size 4, currently holding 3 elements
int new_value = 40;          // The new value we want to append

// Append the new value to the array (at index 3)
arr[3] = new_value;

// Output the updated array
printf("Updated Array:\n");
for (int i = 0; i < 4; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
}
```
As you can see to see all the elements in teh array we must print and loop over every element.
However, if you wish to only see one element in a certain position then you would do this.
```c
int arr[4] = {10,20,30,40}

printf("%d",arr[3]);

```

---
### finding the size of an array if you dont know the elements inside 
The way to do this is by writing 
```c
int nums[] = {2,7,11,13};
int target =9;
int numsSize = sizeof(nums) / sizeof(nums[0]);
printf("The size of the array is %d",numsSize);

```

## 2D Arrays
2D arrays are similar to 1D array however 2D arrays have two dimensions whilst 1d arrays have only one. This means 2D arrays are more like matrix's with an x and y component.
### Declaration and Initialization
To declare a 2d array you can do this:
```c
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

---

### Memory Layout of 2D Arrays
The elements are stored in row-major order.
an example of this is if we used the matrix previously show then the output would look like this
```c
Index →   0   1   2   3   4   5
Value →   1   2   3   4   5   6
```
This may seem not useful but will come in handy with pointer arithmetic and also function passing.

---

### Output
To output the 2d array 
```c
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        printf("%d ", matrix[i][j]);
    }
    printf("\n");
}
```
Similar to doing it with a 1d array you need to loop over both x and y axis not just the x.

### Traversal Techniques
There are multiple ways of traversing a 2d array for example the most common way is via roe-wise.
How this would look in c is like this:
```c
for (int i = 0; i < 3; i++) {        
    for (int j = 0; j < 3; j++) {    
        printf("%d ", matrix[i][j]);
    }
    printf("\n");
}

```
Another way of doing this is via column wise traversal which instead of going with rows firsts you go with colums first
This would look like this:
```c
for (int j = 0; j < 3; j++) {        
    for (int i = 0; i < 3; i++) {    
        printf("%d ", matrix[i][j]);
    }
    printf("\n");
}
```
another way is via diagonal traversal which would look like this
```c
for (int i = 0; i < 3; i++) {
    printf("%d ", matrix[i][2 - i]);
}
```
This will read elements from the top right to the bottom left. you can also play around with this concept to get the other variants.

---

### Diagonal Elements
to find the elements diagonal to each other from top right to bottom left and then from top left  to top right you eould use these twp loops 
```c
for (int i = 0; i < size; i++) {
    printf("%d ", matrix[i][i]);
}
//from top left to bottom right
```
And:
```c
for (int i = 0; i < size; i++) {
    printf("%d ", matrix[i][size - i - 1]);
}
//from top right to bottom left 
```

---

### Use Cases of 2D Arrays
The use case of 2D arrays are like in graphs,image,Dynamic programming table and many more other ways.

---


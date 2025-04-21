# Structs and enums 

---
## Declaring a struct
A struct is a custom data type in C that groups multiple variables (of different types) into one unit.
Great for modeling real-world objects like Car, Student, or Employee, where each object has multiple properties.
For example look at the example below:

```c

struct Car {
    char brand[20];
    int year;
    float price;
};
```
As you can see all the information are put together that is relevant to the car struct like the brand, year amd price. This would be a good way to group sections of code you need together.

## Using a struct
To use a struct you can do this in multiple ways such as inputting the data in order of the struct.
let's say you wanted multiple cars to use this format well if you can set a certain car lets name car2 with the same attributes and method as inside the car struct.
```c
struct Car myCar = {"Toyota", 2020, 15000.50};
printf("Brand: %s\n", myCar.brand);


```
From this example, you can see that myCar is accessing the brand by using . this shows that we can access select data from the struct and will go in more detail later on.

## Accessing struct using pointers

```c
struct Car *ptr = &myCar;
ptr->price = 16000.75;

```
Similarly, you can also use structs to access the data  by using a pointer to it . what this is basically saying is the pointer points at the myCar variable that holds all the attributes then you use said pointer to then point at a certain attribute this time price.
and set it to a value. This is more efficient because you're accessing the direct memory location.


## Nested structs

```c
struct Engine {
    int horsepower;
};

struct Car {
    char brand[20];
    struct Engine eng;
};
```

You can also nest structs if parts of the struct needs to be broken down even more or has complex parts. This example shows that you got engine and to break down engine more you need to use is horsepower.

## Array of structs
you can also make arrays of structs with is to store multiple instances in an array format which is useful if there's multiple vehicles you are planning to add like in this example:
```c
struct Car cars[2] = {
    {"Ford", 2019, 12000.0},
    {"BMW", 2022, 30000.0}
};
```

## Passing structs to a function

```C

void printCar(struct Car c) {
    printf("Brand: %s\n", c.brand);
}

void printCarPtr(struct Car *c) {
    printf("Brand: %s\n", c->brand);
}

```
This method is similar by passing a struct through the parameters and the name of the struct variable to then access all the attributes, and you can do that either with the . operator or a pointer by creating an alias which is basically a nickname.

## typedef

we use typedef to stop writing struct all the time to make it look more oop and also to keep the neatness of the program.
For example:
```c
typedef struct {
    char brand[20];
    int year;
} Car;

Car myCar = {"Nissan", 2018};
```
## Dynamic memory with structs
```c
Car *carPtr = malloc(sizeof(Car));
strcpy(carPtr->brand, "Mazda");
carPtr->year = 2017;
free(carPtr);
```

We haven't delved into malloc and dynamic memory location but why this will become more common is that you can change the size via runtime therefore not fixed at compile time.

## What is an enums
```c
enum Day { MON, TUE, WED, THU, FRI };
```
As you can see, we used enum to hold the days. what this actually does is give names an integer constant.

## Using enums
```c
enum Day today = WED;

if (today == WED) {
    printf("Midweek grind!\n");
}
```

you can use this to improve th readability of your code as well as handle your if statements and switch statement instead of creating a constant

## Default and custom values
with enums the default numbers start with zero as the first assign word however you can also assign numbers to them yourself if you choose to. This is useful because the can assign values that fit your logic of your program directly.
```c
enum Level { LOW = 1, MEDIUM = 5, HIGH = 10 };
```

## Switch statements using enums
```c
enum Level lvl = MEDIUM;

switch (lvl) {
    case LOW: printf("Low\n"); break;
    case MEDIUM: printf("Medium\n"); break;
    case HIGH: printf("High\n"); break;
}
```
as you can see you can apply enum to your switch statement to improve the readability of your code whilst also mentioning what exactly your picking aka rank enums you'll have to mention the name of the enums.

## typedef with enums
using this will make your code look cleaner and easier to work with.
```c
typedef enum { MALE, FEMALE, OTHER } Gender;
Gender g = FEMALE;
```
## Using enums and structs together

```c
typedef enum { ELECTRIC, DIESEL, PETROL } FuelType;

typedef struct {
    char name[20];
    int year;
    FuelType fuel;
} Vehicle;

Vehicle v1 = {"Tesla", 2021, ELECTRIC};
```
Combines structured data with controlled values. This improves data safety, code readability, and bug prevention.

## Mini project
Refactor the project at 002 with structs and enums and make it more efficient

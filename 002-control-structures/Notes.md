# Notes on control structures such as loops ,if statements and switch statements

## iterative/loop statements
the definition of iterative is the act of repeating a statement either finitely or infinitely.
There are two types of loops which are pre-test loops or post-test loops. in the pre-test loops category there are for and while loops and in post-test loops you have do while loops.
What this means is if your loop is a pre-test loop it checks the expression before looping but do while does it after the loop is completed making it a post-test loop.

---

## for loops
if youre looking for a loop that has a finite amount of times it is being iterated then you would use a for loop.
For example if you was trying to make a script to repeat a phrase 10 times you would write:
```c
for(int i; i < 11;i++){
  printf(%s,userName);
}
```


From this example you can see we first initialise our counter called i then we then state the condition of how much the loop will iterate.
This is shown by i < 11 which means whilst i is less than 11 then it will print the statement.
finally to increment i we use i ++

---

## while loops
While loops are used differently as they are used for situations where you want to loop an infinite amount of time as long as the condition is met.
this can be showcased by this example 
```c
int i = 1
while(i<5){
  printf("%d",i);
  i++;
}
```

This example shows that the loop will keep iterating until the condition is met which seems similar to for loops but you only use for loops if you know for certain how often you want to loop over it 

---

## do while 
the do while loop works similar to a while loop however the loop runs first before checking the condition. Therefore if the condition is true then the loop will continue to run.
An example of this would be 
```c
int i = 1;

do {
  printf("%d\n", i);
  i++;
} while (i <= 5);

return 0;
```

As you can see the loop will keep iterating then check the condition and if the condition is met so i is less than or equal to 5 then it will continue. this means after the 6th loop the program will stop as now i is greater than 5.

---

## if statements 

if statements are used to edge case certain scenarios in your code. for example lets say the program was to ask the user if they are an adult or not then we would use an if statement to test this.
```c
          int age = 20;
          
          if (age >= 18) {
              printf("You're an adult.\n");
          }
          else if (age < 18){
              printf("You're a child.\n");
          else{
              printf("Invalid age.");
```

as you can see the condition are met therefore the user would see whats indented in the condition that met. As well as this if the user was less than 18 you can use an else if which is a way to check another condition on top. Finally if all conditions you want to check has been added you can use an else statement to say if anything else happens besides the ones we wanted to check then do this.

---


## switch statements
a switch statement is an alternative way of doing an if statement. How it works is by doing the expression being evaluated once then if the evaluation matches one of the cases then it will do the code that has been indented under that case. However, if none of the requirements are met then you can use default to catch if none of the requirements are met. 
```c
int day = 3;

switch (day) {
  case 1:
      printf("Monday\n");
      break;
  case 2:
      printf("Tuesday\n");
      break;
  case 3:
      printf("Wednesday\n");
      break;
  default:
      printf("Invalid day\n");
}
```

As you can see as day is evaluated and matches the case as 3 then it will print Wednesday and we use break to prevent fall through which happens because c will keep going unless you tell it to stop by using break

---

## mini project

The mini project for today is to create a terminal-based game where you train a character through battles, gain XP, and choose actions. This should be using all these features we have learnt today.

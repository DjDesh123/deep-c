# Notes on control structures such as loops ,if statements and switch statements

## iterative/loop statements
the definition of interative is the act of repeating a statement either finitely or infinitely.
There are two types of loops which are pre-test loops or post-test loops. in the pre-test loops category there are for and while loops and in post-test loops you have do while loops.
What this means is if your loop is a pre-test loop it checks the expression before looping but do while does it after the loop is completed making it a post-test loop.


## for loops
if youre looking for a loop that has a finite amount of times it is being iterated then you would use a for loop.
For example if you was trying to make a script to repeat a phrase 10 times you would write:
<pre> for(int i; i < 11;i++{
          printf(%s,userName);
      }
</pre>

From this example you can see we first initlise our counter called i then we then state the condiiton of how much the loop will iterate.
This is shown by i < 11 which means whilst i is less than 11 then it will print the statement.
finally to increment i we use i ++

## while loops
While loops are used differently as they are used for situations where you want to loop an infite amount of time as long as the condition is met.
this can be showcased by this example 
<pre  >\
  int i = 1
  while(i<5){
    printf("%d",i);
    i++;
  }
</pre>

This example shows that the loop will keep iterating untill the condition is met which seems similar to for loops but you only use for loops if you know for certain how often you want to loop over it 

## do while 

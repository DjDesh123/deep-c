# Notes on variables, data types and basic structure of a C program


# basic structure of a c pogram

The structure of a C program can be broken down to 5 key parts which are
- Docuementation
- Link
- Declaration
- Main() function
- User defined function


# Documentation 
Normally at the top of the porgram and are written inside comments. This is normally for program related infomation.

# Link
System libraries, header files are linked with the c program using this part. They typically are seen by #include<stdio.h>. Functions liek the printf and scanf functions are initalised via this step.

# Declaration
This is where we deine constants in c programming by #define. You can aslo create a function prototype that tells the compiler that these functions already exsit before the program starts to improve speeds.



# Main() function
this is where we wrtie the logic of the program. For example if we was trying to store the user's name and print a message back to the user saying hello then this logic would be inside the main() function.
This section can be further split to variable declaration part and the executable part which handles the variables that are being declared and the program that is being ran 


# User defined functions
This is where you create your own functions inside your program.
An exampple if you was trying to create a function to find the area which you could define it as:
<pre> ```c float FindArea(float Height, float Length) { // Function logic here return Height * Length * 0.5; // Example: triangle area } ``` </pre>
















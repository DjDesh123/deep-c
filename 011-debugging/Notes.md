# debugging 

---

## why debug 
debugging helps 
- find and fix logic or memroy erros 
- inspect variables values and memeroy
- control progran execution step-by-step

---

## GDB (GNU Debugger)
to set it up you first must compile with debug symbols:
```c
gcc -g program.c -o program
```
start gdb:
```c
gdb ./program 
```

---

## common GDB Commands
the command and description follows:

 - break <line> - set a breakpoint
 - run - run the program 
 - next/n - step to next line (skip function)
 - step/s - step into function
 - continue/c continue after breakpoint
 - print<var> - print variable value
 - backtrace/bt - show call stack 
 - list - show source code 
 - quit - exit gdb

---

## debugging with GDB
step-by-step(GDB):
```c
gcc -g buggy.c -o buggy
gdb ./buggy
```
set a breakpoint:
```c
break main 
```
run program:
```c
run
```
step into the divide function: 
```c
step
```
print variables:
```c
print x 
print y
```
see where it crashes:
```c
continue
backtrace
```
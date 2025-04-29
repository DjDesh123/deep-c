## i/o files

This is a way to handle the save states of a file by reading saved data from a file.


## basic concepts

C handles files using file pointers with teh FILE type (from stdio.h)
an example of this is 
```c
FILE *fp;
```

## Opening a file -fopen()
```c
FILE *fopen(const char *filename, const car *mode)
```
There are multiple types of modes you can select from like 
- "r" for reading the file, but it must exist 
- "w" to write in the file or overwrite
- "a" to append by adding to the end of file
- "r+" to read and write in a file (must exist)
- "w+" to read and write (create or overwrite)
- "a+" to read and append (file created if not exists)

another example of this would be 
```c
FILE *fp = fopen("data.txt", "r");
if (fp == NULL) {
    printf("Error opening file\n");
}
```

## Closing a file -fclose()
Always close a file when you're done by doing this 
```c
fclose(fp);
```

## writing to a file 
there's two ways of doing this you can either write by using fprintf (formatted like a printf)
```c
FILE *fp = fopen("data.txt", "w");
fprintf(fp, "Name: %s, Age: %d\n", "Alice", 25);
fclose(fp);
```
fputs() -writes string
```c
fputs("Hellon world\n",fp);
```
or if you want to just put a single character then you just need to write e
```c
fputc("A",fp);
```

## Reading from a file 

is similar to writing to a file by simply fscanf() fgets() abd fgetc()
the way these work as followed
```c
char name[50];
int age;
fscanf(fp, "%s %d", name, &age);
```

```c
char buffer[100];
fgets(buffer, 100, fp);  // Reads a line (with newline)
```
```c
char ch = fgetc(fp);
```

## Checking for End of file -feof()
an example of this is :
```c
while (!feof(fp)){
    // read loops 
}
```
this is an option, but it would be better to read th return values instead of relying only on feof()

## file positioning
ftell - to get the current position
```c
long pos =ftell(fp)
```
fseek() - move to position
```c
fseek(fp, 0, SEEK_SET);   // Go to beginning
fseek(fp, 0, SEEK_END);   // Go to end
fseek(fp, 10, SEEK_CUR);  // Forward 10 bytes
```
rewind()=go back to start
```c
rewind(fp);
```

## binary files i/o

writing -fwrite()
```c
fwrite(&data, sizeof(data), 1, fp);
```
reading -fread()
```c
fread(&data, sizeof(data), 1, fp);
```
this would be useful fo reading and writing structures

## an example of writing and reading a struct to binary file 
```c
typedef struct {
    char name[50];
    int age;
} Person;

Person p = {"Alice", 25};
FILE *fp = fopen("person.dat", "wb");
fwrite(&p, sizeof(Person), 1, fp);
fclose(fp);

// Reading back
fp = fopen("person.dat", "rb");
Person p2;
fread(&p2, sizeof(Person), 1, fp);
printf("Name: %s, Age: %d\n", p2.name, p2.age);
fclose(fp);
```
this would be useful to create a better example for the refactoring of car-program2

## error handling
```c
if (fp == NULL) {
    perror("File opening failed");
    exit(EXIT_FAILURE);
}
```

## text vs binary files
text file - human-readable (.txt)
binary file - efficient storage but not readable by humans (.dat)

use "r", "w" for text files but "rb", "wb" for binary
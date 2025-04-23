# Dynamic Memory Allocation

---

## what is Dynamic Memory Allocation?
The definition of dynamic memory allocation is allocating memory at runtime from the heap (not at compile time).
Why it is useful is because you dont always have to know exactly how much memory you will need while you run your code giving you flexability.

---

## malloc - Memory Allocation
The purpose of malloc is to allocate a block of memory of size bytes and return a pointer to the first byte.
```c
// allocate memory for 5 integers
int *arr = (int*) malloc(5 * sizeof(int));  
```
Why it is useful is because its a perfect when you know how many items you need during runtime.
Its also an efficient use of memory, especially for arrays or buffers with unknown size beforehand.

---

## calloc - contiguous allocation
the purpose of this is to resize a previously allocated memory block which is useful when you wish to grow or shrink buffers or arrays dynamically.
It also avoids copying data manually to new memory blocks.

---

## free - deallocate Memory block
The purpose of using free is to free the memory that is previously allocated.
this is useful because it keeps your program efficient and stable, especially in long running application.

---

## Check for NULL after Allocation
```c
int *arr = malloc(10 * sizeof(int));
if (arr == NULL) {
    // handle error
}
```
this is useful for if th system runs out of memory and prevents segmentation faults or undefined behavior from dereferencing null pointers.

---

## Memory Leak Awareness
when you allocate memory but never free it causes memory leaks.
Its dangerous becso to ause it can consume memory with no way to reclaim it and can lead to app crashes or degraded performance.

---

## Dangling pointers
Using a pointer after the memory it points to has been freed.
```c
int *p = malloc(sizeof(int));
free(p);

// undefined behavior!
*p = 10;  
```
The fix:
```c
free(p);
p = NULL;
```

---

## Pointer arithmetic with Dynamically Allocated Memory
You can treat malloc'd memory like an array.
```c
int *arr = malloc(5 * sizeof(int));
for (int i = 0; i < 5; i++) {
    arr[i] = i * 2;
}
```
How this useful makes dynamic memory as easy to use as static array.

---

## Struct allocation
```c
typedef struct {
    int x;
    float y;
} Point;

Point *p = malloc(sizeof(Point));
p->x = 10;
p->y = 20.5;
```
this would be a perfect method to create dynamic data structures such as linked lists,trees etc.

---

## mini project

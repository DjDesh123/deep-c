# error handling 

---

## why is error handling important?

c functions often return error codes instead of throwing expections like in other languages. proper error handling helps:

- detect and debug unexpected behavior
- gracefully exits or recovers from fautls 
- log or display useful information 

---

## errno -global error indicator 
errno is a global integer variable defined in <errno.h>.
set by system/library calls to indicate the specific error that occurred.
no reset automatically, so set it to 0 manually before a call if needed 

---

## common error code

these are the macros and meaning 

- EPERM - operation not permitted 
- ENOENT - No such file or directory
- ENOMEN - not enough memory
- EIO - I/O error 
- EINVAL - invalid arguement 

---

## perror - print human-readable error
this will be used to print msg:<error string> to stderr.
uses current value of errno

---

## strerror - converts errno to string 
returns a human retable string for error code.

---

## assert - debugging tool 
defined in <assert.h> and checks a condition at runtime by if false prints error and aborts program.
this would look like this in use
```c
assert(pointer != NULL);
```

---

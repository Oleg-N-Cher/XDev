/*

<alloca.h>: Allocate space in the stack

Functions

void * 	alloca (size_t __size)

Function Documentation

void* alloca ( size_t __size )

Allocate __size bytes of space in the stack frame of the caller.

This temporary space is automatically freed when the function that called alloca() returns to its caller. Avr-libc defines the alloca() as a macro, which is translated into the inlined __builtin_alloca() function. The fact that the code is inlined, means that it is impossible to take the address of this function, or to change its behaviour by linking with a different library.

Returns:
    alloca() returns a pointer to the beginning of the allocated space. If the allocation causes stack overflow, program behaviour is undefined.

Warning:
    Avoid use alloca() inside the list of arguments of a function call. 

http://www.nongnu.org/avr-libc/user-manual/group__alloca.html

*/

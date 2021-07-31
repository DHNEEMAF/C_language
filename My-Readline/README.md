![01](https://user-images.githubusercontent.com/67286684/127748196-af27b57c-4f23-443c-bed0-0e0daea8a3e1.PNG)
# my_readline project in C programming language
The C Library function reads a line from fd and returns it into an allocated string.

It stops when either the newline character is read or when the end-of-file is reached, whichever comes first.

The newline character is not copied to the string. A null character is appended to the end of the string.

## Details
- On success, a pointer to the string is returned. On error, a null pointer is returned. If the end-of-file occurs before any characters have been read, the string remains unchanged.
- Number of characters read will be set by the define READLINE_READ_SIZE, which can have any value greater than 0.
- It can be used in a loop to read an entire file line by line.

## Requirements
Code must be compiled with the flags -Wall -Wextra -Werror.

## Authorized function(s)
- malloc(3)
- free
- read
- open
- close

## Unauthorized function(s)
- lseek
- Any other functions or system calls

## Instruction on how to compile and use my_readline
Because I created a makefile for this program, you can compile by typing `make`
It will give you the output `my_readline`
Feel free to create your own text file (you need to name it `file.txt`).
type in your terminal:
`./my_readline` to read the text file.
To clean/remove the .o files, type `make clean` in your terminal

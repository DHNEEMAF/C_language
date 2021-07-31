![01](https://user-images.githubusercontent.com/67286684/127747710-75d68499-0047-4f7c-8a70-d256acace443.PNG)
# my_printf project in C programming language

The my_printf() function produce output according to a format as described below. The my_printf() functions write output to stdout, the standard output stream;

This function writes the output under the control of a format string that specifies how subsequent arguments (or arguments accessed via the variable-length argument facilities of stdarg(3)) are converted for output.

The format string is composed of zero or more directives: ordinary characters (not %), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments.

Each conversion specification is introduced by the % character. The arguments must correspond properly (after type promotion) with the conversion specifier. After the %, the following appear in sequence:

doux The int (or appropriate variant) argument is converted to signed decimal (d). unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x).
c The int argument is converted to an unsigned char, and the resulting character is written.
s The char * argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NUL character.
p The void * pointer argument is printed in hexadecimal.

## Authorized function(s)

- write(2)
- malloc
- free
- va_start, va_arg, va_copy, va_end (see man 3 stdarg)

## Unauthorized functions
printf and co. (fprintf, sprintf, snprintf, asprintf, dprintf, vprintf, vfprintf, vsprintf, vsnprintf, vasprintf, vdprintf)

## Instruction on how to compile and use my_printf

1. Because I created a makefile for this program, you can compile by typing `make`
- It will give you the output `my_printf`
2. Change what is inside my _printf in main for printing 
3. To clean/remove the .o files, type `make clean` in your terminal

4. add -g3 -fsanitize=address in the CFLAGS inside Makefile to see memory leaks

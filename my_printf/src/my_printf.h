#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

/* my_printf.c */
void my_putchar(char c);

/* my_strlen.c */
int my_strlen(char* ch);

/* convert.c */
char* convert(unsigned long int num, int base);

/* my_puts.c */
void my_puts(char* ch);

/* my_printf.c */
int my_printf(char* format, ...);

/* swap.c */
char* reverse(char* buffer, int end);

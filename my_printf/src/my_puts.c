#include "my_printf.h"

void my_puts(char* ch)
{
int len = my_strlen(ch);
for (int i = 0; i < len; i++)
{
my_putchar(ch[i]);
}
}

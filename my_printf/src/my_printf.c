#include "my_printf.h"

void my_putchar(char c)
{
  write(1, &c, 1);
}

int my_printf(char* format, ...)
{
   char* cross;
   int i;
   char* s;
   unsigned long int n;
   int Count = 0;
   va_list arg;
   va_start(arg, format);
   
  for (cross = format; *cross != '\0';)
    {
        
    while (*cross != '%' && *cross != '\0')
     {
      my_putchar(*cross);
     cross++;
     Count++;
     }

    if (*cross == '%')
        {
            cross++;
switch (*cross)
         {
case 'c':
        i = va_arg(arg, int); 
        my_putchar(i);
        cross++;
        Count++;
        break;
case 'd':
        i = va_arg(arg, int);
        if (i < 0)
        {
        i = -i;
        my_putchar('-');
        Count++;
        }
        my_puts(convert(i, 10));
        cross++;
        Count += my_strlen(convert(i, 10));
        break;
case 'o':
        i = va_arg(arg, unsigned int);
        my_puts(convert(i, 8));
        cross++;
        Count += my_strlen(convert(i, 8));
        break;
case 's':
        s = va_arg(arg, char*);
        if (s == NULL)
        {
        s = "(null)";
        }
        my_puts(s);
        cross++;
        Count += my_strlen(s);
        break;
case 'x':
        i = va_arg(arg, unsigned int);
        my_puts(convert(i, 16));
        cross++;
        Count += my_strlen(convert(i, 16));
        break;
case 'u':
        i = va_arg(arg, unsigned int);
        my_puts(convert(i, 10));
        cross++;
        Count += my_strlen(convert(i, 10));
        break;
case 'p':
        n = va_arg(arg, unsigned long int);
        my_putchar('0');
        my_putchar('x');
        my_puts(convert(n, 16));
        cross++;
        Count += my_strlen(convert(n, 16))+2;
         break;
    }
  }
}
 va_end(arg);
 return Count;
}

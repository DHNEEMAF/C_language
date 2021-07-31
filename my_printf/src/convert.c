#include "my_printf.h"

char* convert(unsigned long int num, int base)
{
    char* str = malloc(1000);
    int i = 0;
    bool isNegative = false;

    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

while (num != 0)
{
int rem = num % base;
str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
num = num / base;
}

if (isNegative) str[i++] = '-';
str[i] = '\0'; 
str = reverse(str, i);
return str;
}

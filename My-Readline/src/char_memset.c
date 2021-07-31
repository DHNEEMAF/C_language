#include "my_readline.h"

char* my_char_memset(char* arr, int c, unsigned long len)
{
    char* dst = arr;
    while (len > 0)
    {
        *dst = (unsigned char)c;
        dst++;
        len--;
    }
    return arr;
}

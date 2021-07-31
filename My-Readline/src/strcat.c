#include "my_readline.h"

char* my_strcat(char* dst, const char* src)
{
    int end = 0;
    while (dst[end] != '\0') end++;
    my_strcpy(&dst[end], src);
    return dst;
}

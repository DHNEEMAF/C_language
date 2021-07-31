#include "my_readline.h"

int find_newline(char* str)
{
    if (my_strlen(str) == 0 || str == NULL) return -1;
    int newlindx = 0;
    while (str[newlindx] != '\0')
    {
        if (str[newlindx] == '\n') return newlindx;
        newlindx++;
    }
    return -1;
}

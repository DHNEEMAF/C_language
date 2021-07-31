#include "my_readline.h"

unsigned long my_strlen(const char* arr)
{
    int lenght = 0;
    while (arr[lenght] != '\0' && arr[lenght]) lenght++;
    return lenght;
}

#include "my_readline.h"

char* my_strcpy(char* param_1, const char* param_2)
{
    int i;
    for (i = 0; i < (int)my_strlen(param_2); i++) param_1[i] = param_2[i];
    param_1[my_strlen(param_2)] = '\0';
    return param_1;
}

char* my_strncpy(char* param_1, const char* param_2, int size)
{
    int i;
    for (i = 0; i < size; i++) param_1[i] = param_2[i];
    param_1[size] = '\0';
    return param_1;
}

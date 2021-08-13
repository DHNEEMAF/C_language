#include "../include/my_ls.h"

int option_is_included(char option, char* options)
{
    for (int i = 0; options[i] != '\0'; i++)
        if (option == options[i]) return 1;
    
    return 0;
}

int is_option(char* str)
{
    if (str[0] == '-' && str[1] != '\0')
        return 1;
    return 0;
}

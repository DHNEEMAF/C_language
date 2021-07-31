#include "my_readline.h"

char* my_readline_rec(int fd, char* last, char* remainder)
{
    unsigned long newsize = my_strlen(last) + my_strlen(remainder) + READLINE_READ_SIZE + 1;
    char buff[READLINE_READ_SIZE + 1];
    my_char_memset(buff, '\0', READLINE_READ_SIZE + 1);
    last = realloc(last, newsize);
    if (find_newline(remainder) >= 0)
    {
        my_strncpy(last, remainder, find_newline(remainder) + 1);
        my_strcpy(buff, &remainder[find_newline(remainder) + 1]);
        my_char_memset(remainder, '\0', READLINE_READ_SIZE + 1);
        my_strcpy(remainder, buff);
        return last;
    }
    while (read(fd, buff, READLINE_READ_SIZE) > 0)
    {
        if (find_newline(buff) >= 0)
        {
            if (my_strlen(remainder)) my_strcpy(last, remainder);
            my_char_memset(remainder, '\0', READLINE_READ_SIZE + 1);
            my_strcpy(remainder, &buff[find_newline(buff) + 1]);
            buff[find_newline(buff) + 1] = '\0';
            my_strcat(last, buff);
            return last;
        }
        else
        {
            if (my_strlen(remainder)) my_strcpy(last, remainder);
            my_strcat(last, buff);
            my_char_memset(remainder, '\0', READLINE_READ_SIZE + 1);
            return my_readline_rec(fd, last, remainder);
        }
    }
    if (my_strlen(remainder)) my_strcpy(last, remainder);
    my_char_memset(remainder, '\0', READLINE_READ_SIZE);
    return last;
}

char* my_readline(int fd)
{
    static char remainder[READLINE_READ_SIZE + 1] = {0};
    char* last = (char*)malloc(1);
    *last = '\0';
    if (read(fd, last, 0) < 0)
    {
        last = NULL;
        return last;
    }
    char* returner = my_readline_rec(fd, last, remainder);
    if (*returner == '\0')
    {
        free(returner);
        return NULL;
    }
    else
        return returner;
}

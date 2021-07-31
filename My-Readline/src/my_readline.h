#include <dirent.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define READLINE_READ_SIZE 5

unsigned long my_strlen(const char* arr);
char* my_strcpy(char* param_1, const char* param_2);
char* my_strncpy(char* param_1, const char* param_2, int size);
char* my_char_memset(char* arr, int c, unsigned long len);
char* my_strcat(char* dst, const char* src);
int find_newline(char* str);
char* my_readline_rec(int fd, char* last, char* remainder);
char* my_readline(int fd);

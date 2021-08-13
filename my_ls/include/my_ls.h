#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

struct stat filestat;

typedef struct s_string_array
{
    int number_of_files;
    char** files_array;
    int* time_of_last_modify;
    int* time_of_last_modify_nsec;
    int* type_of_file;
} string_array;

/* optionds */
int option_is_included(char option, char* options);
int is_option(char* str);

/* print_content.c */
void print_content(int argc, char** argv, char* options);

/* strcmp.c */
int my_strcmp(char* param_1, char* param_2);

/* swap.c */
void swap_int(int* xp, int* yp);
void swap_str(char** xp, char** yp);

/* time_sort.c */
char** ordered_argv(int argc, char** argv, char* options);

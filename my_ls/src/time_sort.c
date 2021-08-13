#include "../include/my_ls.h"

char** ordered_argv(int argc, char** argv, char* options)
{
    int* modify_time_sec = malloc(sizeof(unsigned long)*argc);
    int* modify_time_nsec = malloc(sizeof(unsigned long)*argc);

    for (int i=1; i<argc; i++)
    {
        if (stat(argv[i], &filestat) == -1)
        {
            modify_time_sec[i] = 0;
            modify_time_nsec[i] = 0;
        }
        else
        {
            modify_time_sec[i] = filestat.st_mtim.tv_sec;
            modify_time_nsec[i] = filestat.st_mtim.tv_nsec;
        }
    }

    for (int i = 1; i < argc - 1; i++)
        for (int j = i + 1; j < argc; j++)
            if (my_strcmp( argv[i], argv[j]) > 0)
            {
                swap_str( &argv[i], &argv[j]);
                swap_int(&modify_time_sec[i], &modify_time_sec[j]);
                swap_int(&modify_time_nsec[i], &modify_time_nsec[j]);
            }

    if (option_is_included('t', options) == 1)
            for (int i = 1; i < argc - 1; i++)
                for (int j = i + 1; j < argc; j++)
                {
                    if (modify_time_sec[j] > modify_time_sec[i])
                    {
                        swap_int(&modify_time_sec[i], &modify_time_sec[j]);
                        swap_int(&modify_time_nsec[i], &modify_time_nsec[j]);
                        swap_str( &argv[i], &argv[j]);
                    }
                    if (modify_time_sec[j] == modify_time_sec[i] && modify_time_nsec[j] > modify_time_nsec[i])
                    {
                        swap_int(&modify_time_sec[i], &modify_time_sec[j]);
                        swap_int(&modify_time_nsec[i], &modify_time_nsec[j]);
                        swap_str( &argv[i], &argv[j]);
                    }
                }
    
    return argv;
}

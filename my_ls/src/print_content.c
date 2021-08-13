#include "../include/my_ls.h"

void print_content(int argc, char** argv, char* options)
{
    char** specified_files = malloc(sizeof(argv));

    int number_of_specified_files = 0;
    for (int argument_number = 1; argument_number < argc; argument_number++)
        if (argv[argument_number][1]=='\0'||argv[argument_number][0]!='-')
        {
            specified_files[number_of_specified_files]=malloc(sizeof(argv[argument_number]));
            specified_files[number_of_specified_files]=argv[argument_number];
            number_of_specified_files++;
        }

    if (number_of_specified_files < 1)
    {
        specified_files[0] = malloc(sizeof(char*));
        specified_files[0] = ".";
        number_of_specified_files++;
    }

    for (int current_file=0; current_file < number_of_specified_files; current_file++)
        if (stat(specified_files[current_file], &filestat) == -1)
            printf("my_ls: cannot access '%s': No such file or directory\n", specified_files[current_file]);

    int number_of_regular_files = 0;
    for (int current_file=0; current_file < number_of_specified_files; current_file++)
        if (stat(specified_files[current_file], &filestat) != -1 && (filestat.st_mode & S_IFMT) == S_IFREG)
            {
                printf("%s  ", specified_files[current_file]);
                number_of_regular_files++;
            }
    if (number_of_regular_files > 0)
        printf("\n");
    

    DIR *folder;
    struct dirent *entry;
    string_array current_directory;

    for (int number_of_current_directory = 0; number_of_current_directory < number_of_specified_files; number_of_current_directory++)
    {
        current_directory.files_array = malloc(300);
        current_directory.time_of_last_modify = malloc(sizeof(unsigned long)*300);
        current_directory.time_of_last_modify_nsec = malloc(sizeof(unsigned long)*300);
        current_directory.type_of_file = malloc(sizeof(int)*300);
    
        if (stat(specified_files[number_of_current_directory], &filestat) != -1)
        {
            if((filestat.st_mode & S_IFMT) == S_IFDIR)
            {
                if (number_of_regular_files > 0 && number_of_current_directory == 0)
                    printf("\n");

                if (number_of_specified_files > 1)
                {
                    if (number_of_current_directory > 0)
                        printf("\n\n");
                    printf("%s:\n",specified_files[number_of_current_directory]);
                }

                folder = opendir(specified_files[number_of_current_directory]);

                if(folder == NULL)
                {
                    printf("Unable to read directory\n");
                    closedir(folder);
                }

                /* Read directory entries */
                int file_number = 0;

                while( (entry=readdir(folder)) )
                { 
                    stat(entry->d_name,&filestat);
                    current_directory.files_array[file_number] = entry->d_name;
                    current_directory.type_of_file[file_number] = filestat.st_mode;
                    current_directory.time_of_last_modify[file_number] = filestat.st_mtim.tv_sec;
                    current_directory.time_of_last_modify_nsec[file_number] = filestat.st_mtim.tv_nsec;
                    file_number++;    
                }
                current_directory.number_of_files = file_number;

                closedir(folder);

                if (option_is_included('t', options) == 0)
                    for (int i = 0; i <current_directory.number_of_files - 1; i++)
                        for (int j = i + 1; j < current_directory.number_of_files; j++)
                            if (my_strcmp(current_directory.files_array[i], current_directory.files_array[j])>0)
                            {
                                swap_int(&current_directory.time_of_last_modify[i], &current_directory.time_of_last_modify[j]);
                                swap_int(&current_directory.time_of_last_modify_nsec[i], &current_directory.time_of_last_modify_nsec[j]);
                                swap_str(&current_directory.files_array[i], &current_directory.files_array[j]);
                                swap_int(&current_directory.type_of_file[i], &current_directory.type_of_file[j]);
                            }

                if (option_is_included('t', options) == 1)
                {
                    for (int i = 0; i <current_directory.number_of_files - 1; i++)
                        for (int j = i + 1; j < current_directory.number_of_files; j++)
                            if (current_directory.time_of_last_modify[j]>current_directory.time_of_last_modify[i])
                            {
                                swap_int(&current_directory.time_of_last_modify[i], &current_directory.time_of_last_modify[j]);
                                swap_int(&current_directory.time_of_last_modify_nsec[i], &current_directory.time_of_last_modify_nsec[j]);
                                swap_str(&current_directory.files_array[i], &current_directory.files_array[j]);
                                swap_int(&current_directory.type_of_file[j], &current_directory.type_of_file[i]);
                            }
                    for (int i = 0; i <current_directory.number_of_files - 1; i++)
                        for (int j = i + 1; j < current_directory.number_of_files; j++)
                            if (current_directory.time_of_last_modify[j]==current_directory.time_of_last_modify[i] && current_directory.time_of_last_modify_nsec[j]>current_directory.time_of_last_modify_nsec[i])
                            {
                                swap_int(&current_directory.time_of_last_modify[i], &current_directory.time_of_last_modify[j]);
                                swap_int(&current_directory.time_of_last_modify_nsec[i], &current_directory.time_of_last_modify_nsec[j]);
                                swap_str(&current_directory.files_array[i], &current_directory.files_array[j]);
                                swap_int(&current_directory.type_of_file[i], &current_directory.type_of_file[j]);
                            }
                    for (int i = 0; i <current_directory.number_of_files - 1; i++)
                        for (int j = i + 1; j < current_directory.number_of_files; j++)
                            if (current_directory.time_of_last_modify[j]==current_directory.time_of_last_modify[i] && current_directory.time_of_last_modify_nsec[j]==current_directory.time_of_last_modify_nsec[i] && my_strcmp(current_directory.files_array[i], current_directory.files_array[j])>0)
                            {
                                swap_int(&current_directory.time_of_last_modify[i], &current_directory.time_of_last_modify[j]);
                                swap_int(&current_directory.time_of_last_modify_nsec[i], &current_directory.time_of_last_modify_nsec[j]);
                                swap_str(&current_directory.files_array[i], &current_directory.files_array[j]);
                                swap_int(&current_directory.type_of_file[i], &current_directory.type_of_file[j]);
                            }
                }

                for (int i = 0; i < current_directory.number_of_files; i++)
                {
                    if (option_is_included('a', options) && current_directory.files_array[i][0] == '.')
                        printf("%s  ", current_directory.files_array[i]);
                    if (current_directory.files_array[i][0] != '.')
                        printf("%s  ", current_directory.files_array[i]);
                }
                
                if (number_of_current_directory == number_of_specified_files - 1)
                    printf ("\n");
            }
        }
    
    free(current_directory.files_array);
    free(current_directory.time_of_last_modify);
    free(current_directory.time_of_last_modify_nsec);
    free(current_directory.type_of_file);
    }
    free(specified_files);
}

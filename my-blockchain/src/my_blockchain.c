#include "../include/my_blockchain.h"

char* is_sync(struct blockchain buffer)
{
    for (int i = 0; i < buffer.nodes.size; i++)
        if (buffer.blocks.size != buffer.node_blocks[i].content_size)
            return "-";
    return "s";
}

void get_status(struct blockchain buffer)
{
    char output[18];
    char tmp[16];
    my_strcpy(output, "[");
    my_strcat(output, is_sync(buffer));
    my_itoa(tmp, buffer.nodes.size);
    my_strcat(output, tmp);
    my_strcat(output, "]> ");
    write(1, output, my_strlen(output));
}

char** sort_input(char* input, char separator, int* ac, char** av)
{
    *ac = 0;

    for (int i = 0; input[i]; i++)
    {
        if (input[i] == separator) continue;
        if (*ac % 10 == 0 && *ac != 0)
            av = my_realloc_arr(av, *ac, sizeof(char*) * (*ac + 10));
        av[*ac] = malloc(30);
        int j = 0;
        for (; input[i] != separator && input[i]; j++)
            av[*ac][j] = input[i++];
        av[*ac][j] = '\0';
        i--;
        (*ac)++;
    }

    return av;
}

int check_input(char* input, struct blockchain* buffer)
{
    char** av = malloc(sizeof(char*) * 10);
    int ac;
    int exit_status = 0;

    sort_input(input, ' ', &ac, av);

    for (int i = 0; i < ac && exit_status == 0; i++)
    {
        if (ac >= 2 && my_strcmp(av[i], "add") == 0)
        {
            i++;
            if (add_case(av, ac, &i, buffer) == 1)
                exit_status = 1;
        }
        else if (ac >= 2 && my_strcmp(av[i], "rm") == 0)
        {
            i++;
            if (rm_case(av, ac, &i, buffer) == 1)
                exit_status = 1;
        }
        else if (my_strcmp(av[i], "ls") == 0)
        {
            if (ac > 1)
                i++;
            if (ls_case(av[i], buffer) == 1)
                exit_status = 1;
        }
        else if (my_strcmp(av[i], "sync") == 0)
        {
            if (synchronise(buffer) == 1)
                exit_status = 1;
        }
        else if (my_strcmp(av[i], "quit") == 0)
            exit_status = -1;
        else
        {
            my_puts("Command not found.");
            exit_status = 1;
        }
    }

    free_arr(av, ac);

    return exit_status;
}

void prompt(struct blockchain* buffer)
{
    char* input;
    int exit_status;

    do
    {
        get_status(*buffer);
        input = my_readline(0);
        exit_status = check_input(input, buffer);
        //if (exit_status > 0)
        //    show_error(exit_status);
        free(input);
    } while (exit_status != -1);
}

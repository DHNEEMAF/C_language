#include "my_ls.h"

int main(int argc, char** argv)
{
    char* options = malloc(sizeof(char*));
    options[0] = '-';
    int options_index = 1;

    for (int arg_num = 1; arg_num < argc; arg_num++)
        if (is_option (argv[ arg_num]))
            for (int i = 1; argv[arg_num][i] != '\0'; i++)
            {
                if (argv[arg_num][i] == 'a')
                {
                    if (option_is_included('a', options)) break;
                    options[options_index] = 'a';
                    options_index++;
                }
                else if (argv[arg_num][i] == 't')
                {
                    if (option_is_included('t', options)) break;
                    options[options_index] = 't';
                    options_index++;
                }
                else
                {
                    printf("my_ls: Error: invalid option -- '%c'\n", argv[arg_num][i]);
                    return 0;
                }
            }

    print_content(argc, ordered_argv(argc, argv, options), options);

    free(options);

    return(0);
}

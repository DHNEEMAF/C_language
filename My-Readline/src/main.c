#include "my_readline.h"

int main()
{
    char *str = NULL;
    int fd = open("./file.txt", O_RDONLY);
    while ((str = my_readline(fd)) != NULL){
        printf("%s\n", str);
        free(str);
    }
    close(fd);
    return 0;
}

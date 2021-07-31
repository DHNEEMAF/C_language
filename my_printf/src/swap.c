#include "my_printf.h"

void swap(char* a, char* b)
{
char temp = *a;
*a = *b;
*b = temp;
}

char* reverse(char* buffer, int end)
{
int start = 0;
end = end - 1;

while (start < end)
{
swap(&buffer[start++], &buffer[end--]);
}

return buffer;
}

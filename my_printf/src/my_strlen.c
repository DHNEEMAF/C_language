#include "my_printf.h"

int my_strlen(char* ch)
{
int count = 0;

 if (ch[0] == '\0')
 {
return 0;
 }

 while (*ch) 
 { 
  count++; 
  ch++;
 }
return count;
}

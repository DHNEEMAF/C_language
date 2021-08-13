#include "../include/my_square.h"

void my_square(int row, int column) // void type because it will not return anything
{
    for (int i = 0; i < row; i++) // loop for i for printing rows
    {
        for (int j = 0; j < column; j++) // loop for j for printing columns
        {
            if ((i == 0 || i == row - 1) && (j == 0 || j == column - 1)) // this loop for printing "o" sign
            {
                printf("o");
            }
            else if ((i > 0) && ((j == 0) || j == column - 1)) // this loop for printing "|" sign
            {
                printf("|");
            }
            else if ((i == 0 || i == row - 1) && (j >= 1 && j <= column - 2 )) // this loop for printing "-" sign
            {
                printf("-");
            }
            else {
                printf(" "); // to print empty
            }      

        }
    printf("\n"); // to make a new line
    }    
}

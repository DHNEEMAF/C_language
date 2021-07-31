#include "mastermind.h"

/* Function to generate random array of unique numbers from 0-7 to use as indexes from pieces list. */
int *pickRandomNumber() 
{
    //srand seeds the random number generator used by the function rand
    srand(time(0));                                        // Initialization, should only be called once.
    int *codeIndex = malloc(sizeof(int) * 4);
    int r = rand() % 8;                                    // "%" sign is the modulus Operator and remainder of after an integer division
    codeIndex[0] = r;                                      //first random number
    r = rand() % 8;                                        //generate next random and check
    if (r != codeIndex[0])                                 //make sure its unique, if not regenerate until....
    {
        codeIndex[1] = r;
    }
    else
    {
        while (r == codeIndex[0])
        {
            r = rand() % 8;
        }
        codeIndex[1] = r;
    }
    /* same for 3rd index */
    if (r != codeIndex[0] && r != codeIndex[1])
    {
        codeIndex[2] = r;
    }
    else
    {
        while (r == codeIndex[0] || r == codeIndex[1])
        {
            r = rand() % 8;
        }
        codeIndex[2] = r;
    }
    /* same for 4th index */
    if (r != codeIndex[0] && r != codeIndex[1] && r != codeIndex[2])
    {
        codeIndex[3] = r;
    }
    else
    {
        while (r == codeIndex[0] || r == codeIndex[1] || r == codeIndex[2])
        {
            r = rand() % 8;
        }
        codeIndex[3] = r;
    }
    return codeIndex;
}

/* Function to validate if user input code string is of correct length and of unique numbers. */
int uniqueValidator(char *code)
{
    int i = 0;
    int count = 0;
    while (code[i] != '\0')
    {
      if (code[i] >= '0' && code[i] <= '9')
      {
        count++;
        i++;
      }
      else
      {
        break;
      }
    }
    if ((count == 4) && (strlen(code) == 4))
    {
      return 0;
    }
    else
    {
      return 1;
    }
}

/* Function to validate if user input pieces string is correct length and of unique numbers. */
int uniquePiecesValidator(char *pieces)
{
    int i = 0;
    int j = 0;
    int count = 0;
    while (pieces[i] != '\0')
    {
        if (pieces[i] >= '0' && pieces[i] <= '7')
        {
            i++;
        }
        else
        {
            count++;
            i++;
        }
    }
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (pieces[i] == pieces[j])
                count++;
        }
    }
    if ((count == 8) && (strlen(pieces) == 8))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

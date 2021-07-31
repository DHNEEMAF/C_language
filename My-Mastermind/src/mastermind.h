#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* game functions */
int *pickRandomNumber();                       //get random number 
int uniqueValidator(char *code);               //check valid unique number code of 4 digits entered
int uniquePiecesValidator(char *pieces);       //check valid unique number of 8 pieces

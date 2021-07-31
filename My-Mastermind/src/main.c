#include "mastermind.h"

int main(int ac, char **av)      //from My Square
{
    int uniqueValidator(char *code);
    int uniquePiecesValidator(char *pieces);
    int *pickRandomNumber();
    int i, j;                           //loop indexes
    char pieces[9] = "01234567";        //default pieces if no input parameter
    char code[5] = "0000";              //4 digit Code Character String
    int tries = 10;                     //default attempts if no input paramter
    int Flag = 0;                       //flag for user input code, 0 = no user input
    int inputFailureFlag = 0;           //flag to show input failure and exit out of program to allow restart.

    /* cases for cmd line user input game paramters -c CODE, -p PIECES, -t TRIES */
    for (int i = 0; i < ac; i++)
    {
        if (strcmp(av[i], "-p") == 0)
        {
            if (uniquePiecesValidator(av[i + 1]) == 0) //check valid unique number of 8 pieces
            {
                int len = strlen(av[i + 1]);
                for (int j = 0; j < len; j++)
                {
                    pieces[j] = av[i + 1][j]; //overwrite the default pieces if valid
                }
            }
            else
            {
                printf("PIECES input format: 8 UNIQUE NUMBERS 0-9 '-p XXXXXXXX', RE-INPUT GAME PARAMETERS OR LEAVE TO DEFAULT\n");
                inputFailureFlag++; //if not valid code, flag input failure to exit program after!
            }
        }
        if (strcmp(av[i], "-c") == 0) //find a user input secret code on execution
        {
            Flag++;
            if (uniqueValidator(av[i + 1]) == 0) //check valid unique number code of 4 digits entered
            {
                int len = strlen(av[i + 1]);
                for (int j = 0; j < len; j++)
                {
                    code[j] = av[i + 1][j]; //overwrite the default code if valid
                }
            }
            else
            {
                printf("CODE input format: 4 UNIQUE NUMBERS FROM USERS PIECES OR 0-7 IF DEFAULT PIECES: '-c XXXX', RE-INPUT GAME PARAMETERS OR LEAVE TO DEFAULT\n");
                inputFailureFlag++; //if not valid code, flag input failure to exit program after!
            }
        }
        if (strcmp(av[i], "-t") == 0) //find input of user attempts parameter on execution
        {
            if (atoi(av[i + 1]) > 0 && atoi(av[i + 1]) < 100)
            {
                tries = atoi(av[i + 1]);
            }
            else
            {
                printf("TRIES input format: NUMBER 0-99 '-t XX', RE-INPUT GAME PARAMETERS OR LEAVE TO DEFAULT\n");
                inputFailureFlag++; //if not valid code, flag input failure to exit program after!
            }
        }
    }
    if (inputFailureFlag != 0) //Exit if user input invalid game parameters force to execute again
    {
        return 1;
    }
    else //Else continue running the program
    {
        //if no user input valid secret code
        if (Flag == 0)
        {
            int *codeIndex = pickRandomNumber(); //make Random code from pieces string
            /* The secret code
            // for (i = 0; i < 4; i++){
            //   printf("codeIndex: %d\n",codeIndex[i]); 
            // } */
            for (i = 0; i < 4; i++)
            {
                code[i] = pieces[codeIndex[i]];
            }
            free(codeIndex); //free malloc from pickRandomNumber()
        }
        //outline the game and its parameters, exit option, and start attempts.
        printf("-------------\n");
        printf("Can You Guess The SECRET CODE: XXXX\n");
        printf("-------------\n");
        if (Flag == 0)
            printf("Secret Code: RANDOM\n");
        else
            printf("Secret Code: USER INPUT\n");
        printf("Pieces: %s\n", pieces);
        printf("Tries: %d\n", tries);
        printf("Enter 'q' to quit at any point!\n");
        printf("-------------\n");
        printf("Try 1:\n");

        /* Actual game mechanics of guesses here */
        char buf[5];
        int count = 1;
        int wellPlaced;
        int misPlaced;
        while (1) //infinite game loop until broken
        {
            if (count <= tries) //while there are tries remaining
            {
                read(0, buf, sizeof(buf)); //take user input guesses
                buf[4] = '\0';             //null terminate user input string
                /* escape key (q)uit to leave game */
                if (buf[0] == 'q')
                    return 1;
                wellPlaced = 0; //re-initialise to 0 for each guess loop
                misPlaced = 0;
                //test guess for correct input i.e 4 unique numbers
                if (uniqueValidator(buf) != 0)
                {
                    printf("Wrong Input!\n"); //if invalid, dont register as an tries and notify player
                }
                else //otherwise test the guess
                {
                    for (i = 0; i < 4; i++) //nested loops to compare user guess and secret code
                    {
                        for (j = 0; j < 4; j++)
                        {
                            if (buf[i] == code[j] && i == j) //number is matched and in place
                            {
                                wellPlaced++; //increment wellPlaced pieces when occur
                            }
                            else if (buf[i] == code[j] && i != j) //number is matched but not in place
                            {
                                misPlaced++; //increment misPlaced pieces when occur
                            }
                        }
                    }
                    if (wellPlaced == 4) //if correct guess, winner message & exit out.
                    {
                        printf("Congratulations! YOU WIN!\n");
                        break;
                    }
                    else //else increment tries, give hints and continue game.
                    {
                        count++;
                        printf("Well placed pieces: %d\n", wellPlaced);
                        printf("Misplaced pieces: %d\n", misPlaced);
                    }
                    printf("-------------\n");
                    printf("Try %d:\n", count);
                }
            }
            else //no tries remaining, display failure and exit!
            {
                printf("You have no tries left, Loser!!\n");
                break;
            }
        }
    }
}

![01](https://user-images.githubusercontent.com/67286684/127747976-44c340a3-15a2-4499-a018-8e266d42f805.PNG)
# My Mastermind project in C programming language

Mastermind is a game composed of 8 pieces of different colors. A secret code is then composed of 4 distinct pieces.

The player has 10 attempts to find the secret code. After each input, the game indicates to the player the number of well placed pieces and the number of misplaced pieces.

Pieces will be '0' '1' '2' '3' '4' '5' '6' '7'.

If the player finds the code, he wins, and the game stops. A misplaced piece is a piece that is present in the secret code butthat is not in a good position.

This program was created using two files (my_square.c and main.c). Also, it has Makefile, gitignore and mastermind.h.

This program was created using the follwing functions:

- int pickRandomNumber(); which is for getting random numbers
- int uniqueValidator(char *code); which is for checking valid unique number code of 4 digits entered
- int uniquePiecesValidator(char *pieces); which if for checking valid unique number of 8 pieces

## Authorized function(s)

- printf(3)
- write(2)
- read(2)
- rand()
- srand()
- time()

## Unauthorized function(s)

- Any functions/syscalls which does not appear in the previous list

## Instruction on how to compile and use my_mastermind
1. Because I created a Makefile for this program, you can compile all files by typing `make`
- It will give you the output `mastermind`
2. Type `./mastermind` in your terminal to start the game
3. To clean/remove the .o files, type `make clean` in your terminal

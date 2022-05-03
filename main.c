#include <stdio.h>
#include <stdlib.h>
#include "tic_board.h"
#define TIC_N 3


int main()
{
    Tic_Matrix board;
    initMatrix(&board);

    turn(&board, 'X', 1, 1);
    turn(&board, 'O', 2, 2);
    turn(&board, 'X', 1, 3);
    turn(&board, 'O', 2, 1);
    turn(&board, 'X', 1, 2);
    turn(&board, 'O', 3, 1);
    turn(&board, 'X', 3, 2);
    turn(&board, 'O', 3, 3);


    char c;
    getc(stdin);
}

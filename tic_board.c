#include <stdio.h>
#include <stdlib.h>
#include "tic_board.h"


void initMatrix(Tic_Matrix * pntr_tm)
{
    for(int i = 0; i < TIC_N; i++)
    {
        pntr_tm -> x[i].counter = 0;
        pntr_tm -> y[i].counter = 0;
    }

    pntr_tm -> diag1.counter = 0;
    pntr_tm -> diag2.counter = 0;
}

void win(bool is_x)
{
    if(is_x)
        printf("Player X win");
    else
        printf("Player O win");

    getc(stdin);
    exit(0);
}

void turn(Tic_Matrix * pntr_tm, char entry, int x, int y)
{
    bool is_x = entry == 'X' ? 1 : 0;

    // Check if entry belong to the first diagonal
    if(x == y)
    {
        // Check if entry is different from entries across diag1
        if(pntr_tm -> diag1.counter && is_x != pntr_tm -> diag1.is_x || pntr_tm -> diag1.counter == -1)
            pntr_tm -> diag1.counter = -1;
        else
        {
            pntr_tm -> diag1.counter++;
            pntr_tm -> diag1.is_x = is_x;
        }

        // Check a win
        if(pntr_tm -> diag1.counter == TIC_N)
            win(pntr_tm -> diag1.is_x);
    }

    // Check if entry belong to the second diagonal
    if((TIC_N - x) == (y - 1))
    {
        // Check if entry is different from entries across diag2
        if(pntr_tm -> diag2.counter && is_x != pntr_tm -> diag2.is_x || pntr_tm -> diag2.counter == -1)
            pntr_tm -> diag2.counter = -1;
        else
        {
            pntr_tm -> diag2.counter++;
            pntr_tm -> diag2.is_x = is_x;
        }

        // Check a win
        if(pntr_tm -> diag2.counter == TIC_N)
            win(pntr_tm -> diag2.is_x);
    }

    // Check if entry is different from entries across column x
    if(pntr_tm -> x[x].counter && is_x != pntr_tm -> x[x].is_x || pntr_tm -> x[x].counter == -1)
        pntr_tm -> x[x].counter = -1;
    else
    {
        pntr_tm -> x[x].counter++;
        pntr_tm -> x[x].is_x = is_x;
    }
    // Check if entry is different from entries across row y
    if(pntr_tm -> y[y].counter && is_x != pntr_tm -> y[y].is_x || pntr_tm -> y[y].counter == -1)
        pntr_tm -> y[y].counter = -1;
    else
    {
        pntr_tm -> y[y].counter++;
        pntr_tm -> y[y].is_x = is_x;
    }

    // Check a win
    if(pntr_tm -> x[x].counter == TIC_N)
        win(pntr_tm -> x[x].is_x);

    if(pntr_tm -> y[y].counter == TIC_N)
        win(pntr_tm -> y[y].is_x);
}

void clear(Tic_Matrix * pntr_tm)
{
    for(int i = 0; i < TIC_N; i++)
    {
        pntr_tm -> x[i].counter = 0;
        pntr_tm -> y[i].counter = 0;
    }

    pntr_tm -> diag1.counter = 0;
    pntr_tm -> diag2.counter = 0;
}

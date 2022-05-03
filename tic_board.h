#pragma once
#include <stdbool.h>
#define TIC_N 3


typedef struct tic_cell
{
    int counter;
    bool is_x;
} Tic_Cell;

typedef struct tic_matrix
{
    Tic_Cell x[TIC_N];
    Tic_Cell y[TIC_N];
    Tic_Cell diag1;
    Tic_Cell diag2;
} Tic_Matrix;

void initMatrix(Tic_Matrix*);
void turn(Tic_Matrix*, char, int, int);
void clear(Tic_Matrix*);

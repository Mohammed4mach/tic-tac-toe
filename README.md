# Tic-Tac-Toe

The problem described here:   

![The problem is here](https://github.com/Mohammed4mach/tic-tac-toe/blob/main/Tic-tac-toe.jpg)

<hr>

## The Solution

My solution is a data structure named `Tic_Matrix`, its components is two arrays and two variables: 
- array `x` for columns
- array `y` for rows
- `diag1` for the first diagonal
- `diag2` for the second diagonal

These variables are of type struct named `Tic_Cell`, its components:
- `counter` of type integer
- `is_x` is true when entries is X

![The data structure](https://github.com/Mohammed4mach/tic-tac-toe/blob/main/Tic%20Matrix.png)

When turn is taking place, lets say, put X on the cell at second column and third row:

    turn(board, 'X', 2, 3);
    
If the 2<sup>nd</sup> column not contain any entries, `counter` of the 2<sup>nd</sup> variable in the array `x` will incremented and `is_x` will be true. Same thing happen to 3<sup>rd</sup> row.   
Turn after turn, whenever any counter reachs n (number of rows), the program check `is_x` of the variable that the counter belongs to, if it is true player X wins, if false player O wins.   
If a play is made that O is putted in a column or a row have X, the counter of that column will be -1, to end of the game.

Same thing happen to the diagonals `diag1` & `diag2`, but the trick here is to know if the current cell belongs to any diagonal. 

![Matrix](https://github.com/Mohammed4mach/tic-tac-toe/blob/main/grid.png)

At the first time, I tried to recognize a pattern where the cell does not belong to a diagonal, but this seemed go randomly especially when n is a large number.   
After that I tried the opposite, so I recognized the pattern for the first diagonal - when row number = column number. The second diagonal had been more tricky. After a while, the other pattern came to my mind. If x is the column and y is the row, the cell belongs to the 2<sup>nd</sup> diagonal when (n - x) = (y - 1).

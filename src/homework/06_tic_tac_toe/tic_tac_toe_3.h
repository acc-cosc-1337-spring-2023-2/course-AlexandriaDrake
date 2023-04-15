//h

#include "tic_tac_toe.h"

//1. Create a class that inherits from TicTacToe.
class tic_tac_toe3 : public tic_tac_toe
{
    public:
        /*2. Create a default constructor (no parameters).
        a. Create an initializer to initialize TicTacToe with a value of 3.
        Example: DeriveConstructor(): BaseConstructor(3){}*/
        tic_tac_toe3() : tic_tac_toe(3){}
    
    private:

        /*3. Create private functions  check_column_win, check_row_win, and check_diagonal_win   
        with no parameters that return a bool.*/
        bool check_row_win();
        bool check_column_win();
        bool check_diagonal_win();

};
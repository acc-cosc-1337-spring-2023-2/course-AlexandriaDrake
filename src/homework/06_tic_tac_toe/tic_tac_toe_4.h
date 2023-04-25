//h

#include "tic_tac_toe.h"

//1. Create a class that inherits from TicTacToe.
class tic_tac_toe4 : public tic_tac_toe
{
    public:
        /*2. Create a default constructor (no parameters).
        a. Create an initializer to initialize TicTacToe with a value of 4.*/
        tic_tac_toe4() : tic_tac_toe(4){}
        /*Homework 10 Update  a) in .h file add a new constructor TicTacToe4(std::vector<string> p, string winner) //more code here
        Don’t forget to pass p and winner to TicTacToe via constructor*/
        tic_tac_toe4(vector<string> p, string winner) : tic_tac_toe(p, winner) {}
    
    private:

        /*3. Create private functions  check_column_win, check_row_win, and check_diagonal_win   
        with no parameters that return a bool.*/
        bool check_row_win();
        bool check_column_win();
        bool check_diagonal_win();

};

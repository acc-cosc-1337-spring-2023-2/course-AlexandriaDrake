//h
#include "tic_tac_toe.h"
#include<memory>


using std::unique_ptr; 

#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H

// Create a TicTacToeData class.
/*  a) Add class function void save_games(const std::vector<std::unique_ptr<TicTacToe>>& games)
Algorithm: Open file for writing
For each vector of TicTacToe
For each char in string
Write char to file  
end char in string loop
Write get winner of game to file
Write a new line end vector of TicTacToe loop
b) Add  std::vector<std::unique_ptr<TicTacToe>> get_games() function.
Algorithm to restore a vector of unique ptr of TicTacToe from file.
(Each line in the file is a game(vector of string), each character in the line is the , and from left to right position 0,1, etc.). 
The last character in each line is the game winner.
*/

class tic_tac_toe_data
{
    public:
        void save_games(const vector<unique_ptr<tic_tac_toe>>& games);
        vector<unique_ptr<tic_tac_toe>>get_games();
};

#endif
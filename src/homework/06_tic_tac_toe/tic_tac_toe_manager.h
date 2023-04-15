//h
#include "tic_tac_toe.h"
#include <vector>
#include <iostream>
#include <memory>

using std::ostream; using std::vector; using std::unique_ptr;

#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H


    /*2. Change save_game TicTacToe parameter to a unique_ptr of TicTacToe reference.
    a.  In save_game make sure update_winner_count is the first statement (Use -> instead of .  
          for get_winner).
    b.  In save_game change games.push_back, add the move statement to game variable.*/

    /*3. Change the friend function ostream overload code to account for unique pointers.
     a. Add a reference to the loop auto& game, unique pointers must be referenced..
     b. Account for dereferencing pointers in the loop block, change game to *game.*/

class tic_tac_toe_manager
{
    private:

        /*  1. Change the games vector to a vector of unique ptr to TicTacToe.
        Example: vector<unique_ptr<BankAccount>> accounts;*/
        vector<unique_ptr<tic_tac_toe>> games;
        int x_win = 0;
        int o_win = 0;
        int ties = 0;
        void update_winner_count(std::string);

    public:
        void get_winner_totals(int& x, int& o, int& t);
        //2. Change save_game TicTacToe parameter to a unique_ptr of TicTacToe reference.
        void save_game(unique_ptr<tic_tac_toe>& b);
        friend std::ostream& operator<<(std::ostream& out, const tic_tac_toe_manager& manager);
        
};

#endif


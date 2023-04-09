//cpp
#include"tic_tac_toe_manager.h"
#include"tic_tac_toe.h"

//add the TicTacToe to games vector with push_back, call update winner count pass the winner from TicTacToe to update x, o, or tie totals.
void tic_tac_toe_manager::save_game(tic_tac_toe b)
{
    games.push_back(b);
    update_winner_count(b.get_winner());
}

//Overload <<-Loop through vector of TicTacToe and call the TicTacToe cout overload.

std::ostream& operator<<(std::ostream& out, const tic_tac_toe_manager& manager)
{
    for (const auto& game : manager.games)
    {
        out<<game<<"\n";
    }
    return out; 
}

//Use references to get the winners  

void tic_tac_toe_manager::get_winner_totals(int& x, int& o, int& t)
{
    x = x_win;
    o = o_win;
    t = ties;
};

//Create a vector of TicTacToe named games-- initialize int x_win, int o_win, and int ties to 0

//if winner X increment x_win, if winner O increment o_win, and else increment ties 

void tic_tac_toe_manager::update_winner_count(string winner)
{
    if(winner == "X")
    {
        x_win++;
    }
    else if(winner == "O")
    {
        o_win++;
    }
    else
    {
        ties++;
    }

}
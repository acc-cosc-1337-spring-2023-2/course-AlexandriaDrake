//cpp
#include"tic_tac_toe_manager.h"
#include"tic_tac_toe.h"

/* Homework 10 Update: c) Add a TicTacToeManager constructor with TicTacToeData reference parameter. (Read data from file)
 Assign constructor argument to private variable data.
In the .cpp file write constructor code to initialize private games vector by calling TicTacToeData get_games function
Loop through games,  Write code to update the winner counts.
*/
tic_tac_toe_manager::tic_tac_toe_manager(tic_tac_toe_data& data) : data(data) 
{
    games = data.get_games();
    for (const auto& game : games)
    {
        update_winner_count(game->get_winner());
    }
}

tic_tac_toe_manager::~tic_tac_toe_manager()
{
    data.save_games(games);
}

/* HW 9 Update: 2. Change save_game TicTacToe parameter to a unique_ptr of TicTacToe reference.
            a.  In save_game make sure update_winner_count is the first statement (Use -> instead of .  
            for get_winner).
            b.  In save_game change games.push_back, add the move statement to game variable.*/

//add the TicTacToe to games vector with push_back, call update winner count pass the winner from TicTacToe to update x, o, or tie totals.
void tic_tac_toe_manager::save_game(unique_ptr<tic_tac_toe>& b)
{
    update_winner_count(b->get_winner());
    games.push_back(std::move(b));
}

  /* HW 9 Update: 3. Change the friend function ostream overload code to account for unique pointers.
     a. Add a reference to the loop auto& game, unique pointers must be referenced..
     b. Account for dereferencing pointers in the loop block, change game to *game.*/
//Overload <<-Loop through vector of TicTacToe and call the TicTacToe cout overload.

std::ostream& operator<<(std::ostream& out, const tic_tac_toe_manager& manager)
{
    for (const auto& game : manager.games)
    {
        out<<*game<<"\n";
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


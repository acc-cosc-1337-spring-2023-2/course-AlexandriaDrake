//cpp

#include<tic_tac_toe.h>
#include<iostream>
#include<string>

using std::cout; using std::cin; using std::endl;

string tic_tac_toe::get_player() const {return player;}

bool tic_tac_toe::game_over() {return check_board_full();}

void tic_tac_toe::start_game(string first_player)
{
    while (first_player != "X" && first_player != "O")
    {
        cout<<"Invalid selection. Please enter X or O: ";
        cin>>first_player;
    }

    player = first_player;

    clear_board();
}

void tic_tac_toe::mark_board(int position)
{
    pegs[position -1] = player;
    set_next_player();
}

void tic_tac_toe::display_board() const 
{
    cout << endl;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cout << " " << pegs[i * 3 + j] << " ";
            if (j < 2) cout << "|";
        }
        if (i < 2) cout << "\n---+---+---\n";
    }
    cout << endl;
}

void tic_tac_toe::set_next_player()
{
    if (player == "X")
        player = 'O';
    else
        player = 'X';
}

bool tic_tac_toe::check_board_full() 
{
    for (auto pegs : pegs) 
    {
        if (pegs == " ") 
        {
            return false;
        }
    }
    return true;
}

void tic_tac_toe::clear_board()
{
    for (int i = 0; i < 9; i++)
    {
        pegs[i] = " ";
    }
}


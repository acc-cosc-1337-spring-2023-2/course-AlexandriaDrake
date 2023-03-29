//cpp

#include<tic_tac_toe.h>
#include<iostream>
#include<string>

using std::cout; using std::cin; using std::endl;

bool tic_tac_toe::game_over()
{
    return check_board_full();
}

void tic_tac_toe::start_game(string first_player)
{
    if (first_player == "X" || first_player == "O")
    {
        player = first_player;
        clear_board();
    }
    else
    {
        cout << "Invalid player selection. Please choose X or O.\n" << endl;
    }
}

void tic_tac_toe::mark_board(int position)
{
    if (position >= 1 && position <= 9 && pegs[position - 1] == " ")
    {
        pegs[position -1] = player;
        set_next_player();
    }
    else
    {
        cout << "Invalid position. Please choose an empty position between 1 and 9.\n" << endl;
    }
}

string tic_tac_toe::get_player() const
{
    return player;
}

void tic_tac_toe::display_board() const
{
    for (int i = 0; i < 9; i +=3)
    {
        std::cout << " " << pegs[i] << " | " << pegs [i+2] << " | " << pegs[i+2] << "\n";
        if (i !=6)
        {
            std::cout << "---|---|---\n";
        }
    }
}

void tic_tac_toe::set_next_player()
{
    if (player == "X")
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }
}

void tic_tac_toe::clear_board()
{
    for (int i = 0; i < 9; i++)
    {
        pegs[i] = " ";
    }
}

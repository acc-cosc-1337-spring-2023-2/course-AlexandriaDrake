//cpp

#include<tic_tac_toe.h>
#include<iostream>
#include<string>

using std::cout; using std::cin; using std::endl;

string tic_tac_toe::get_player() const 
{
    return player;
}

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

//void tic_tac_toe::display_board() const ***Removed for HW 8***
/*  Overload the ostream operator << (cout)  this code will replace display_board function
    a) In overloaded operator function output the board
    b) remove the display_board function from your code including from header.*/

std::ostream& operator<<(std::ostream& out, const tic_tac_toe& game)
{
    out << endl;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            out << " " <<game.pegs[i * 3 + j] << " ";
            if (j < 2) out << "|";
        }
        if (i < 2) out << "\n---+---+---\n";
    }
    out << endl;
    return out;
}

/* Overload the istream operator >> (cin) 
    a) From main.cpp, move the code that capture position including the  the cout<<"Enter position" code
    b) After capturing position call the mark_board function */

std::istream& operator>>(std::istream& in, tic_tac_toe& game)
 {
    int position;
    while (true)
        {
            cout << "\nPlayer " << game.get_player() << ", enter a position for spaces 1 through 9: ";            
            in >> position;
            if(position >=1 && position <=9)
            {
                break;
            }
            else
            {
                cout<<"Invalid position. Please select a position 1 through 9: \n";
            }
        }

        game.mark_board(position);
        return in;
        //game.display_board(); ***Removed for HW 8***
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
    for (auto peg : pegs) 
    {
        if (peg == " ") 
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

void tic_tac_toe::set_winner()
{
    if (player == "X")
    {
        winner = "O";
    }
    else
    {
        winner = "X";
    }
}

string tic_tac_toe::get_winner()
{
    return winner;
}

bool tic_tac_toe::game_over() 
{
    if(check_row_win() == true || check_column_win() == true || check_diagonal_win() == true)
    {
        set_winner();
        return true;
    }
    else if(check_board_full() == true)
    {
        winner = "C";
        return true;
    }
    else
    {
        return false;
    }
}

bool tic_tac_toe::check_row_win()
{
    for(int i = 0; i <9; i+=3)
    {
        if(pegs[i] == "O" && pegs[i+1] == "O" && pegs[i+2] == "O")
        {
            return true;
        }
        else if(pegs[i] == "X" && pegs[i+1] == "X" && pegs[i+2] == "X")
        {
            return true;
        }
    }
    return false;
}

bool tic_tac_toe::check_column_win()
{
    for(int i = 0; i <3; i++)
    {
        if(pegs[i] == "O" && pegs[i+3] == "O" && pegs[i+6] == "O")
        {
            return true;
        }
        else if(pegs[i] == "X" && pegs[i+3] == "X" && pegs[i+6] == "X")
        {
            return true;
        }
    }
    return false;
}

bool tic_tac_toe::check_diagonal_win()
{
    if (pegs[0] == "X" && pegs[4] == "X" && pegs[8] == "X")
    {
        return true;
    }
    else if (pegs[6] == "X" && pegs[4] == "X" && pegs[2] == "X")
    {
        return true;
    }
    else if (pegs[0] == "O" && pegs[4] == "O" && pegs[8] == "O")
    {
        return true;
    }
        else if (pegs[6] == "O" && pegs[4] == "O" && pegs[2] == "O")
    {
        return true;
    }
    return false;
}



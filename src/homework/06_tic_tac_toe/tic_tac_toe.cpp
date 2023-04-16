//cpp

#include <tic_tac_toe.h>
#include <iostream>
#include <string>
#include <cmath>


using std::cout; using std::cin; using std::endl;

/*1. Create a constructor with an int parameter named size.
     a. in the constructor use an initializer list to initialize the vector to 9 or 16 elements
        HINT(multiply 3 or 4 by itself)
        Example: SomeConstructor(int s) :some_vector(s*s, " " ){}//this will initialize some_vector to s*s elements of " " */
        
tic_tac_toe::tic_tac_toe(int size) : pegs(size*size, " "){}


string tic_tac_toe::get_player() const 
{
    return player;
}

void tic_tac_toe::start_game(string first_player)
{
    if (first_player == "X" || first_player == "O")
    {
         player = first_player;
    }

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


std::ostream& operator<<(std::ostream& out, const tic_tac_toe& game) //Pretty horizontal/vertical board won't format correctly. :(
{
    int row_size = sqrt(game.pegs.size());
    int size = static_cast<int>(game.pegs.size());
    for (int i = 0; i < size; i++)
    {
        out << game.pegs[i];
        if ((i + 1) % row_size == 0) 
        {
            out << "\n";
        } else {
            out << "|";
        }
    }
    out<<"\n";
    return out;
}

/* Overload the istream operator >> (cin) 
    a) From main.cpp, move the code that capture position including the  the cout<<"Enter position" code
    b) After capturing position call the mark_board function */

std::istream& operator>>(std::istream& in, tic_tac_toe& game)
 {
    int position;
    int board_size = game.pegs.size();
    while (true)
        {
            cout << "\nPlayer " << game.get_player() << ", enter a position for spaces 1 through "<<board_size<<": ";            
            in >> position;
            if(position >=1 && position <= board_size)
            {
                break;
            }
            else
            {
                cout<<"Invalid position. Please select a position 1 through "<<board_size<<": \n";
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
    for (int i = 0; i < pegs.size(); i++) 
    {
        if (pegs[i] == " ") 
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

 /*5. In TicTacToe functions  check_column_win, check_row_win, and check_diagonal_win ,
    remove code leaving only the statement return false.*/
bool tic_tac_toe::check_row_win()
{
    return false;
}

 /*5. In TicTacToe functions  check_column_win, check_row_win, and check_diagonal_win ,
    remove code leaving only the statement return false.*/
bool tic_tac_toe::check_column_win()
{
    return false;
}

 /*5. In TicTacToe functions  check_column_win, check_row_win, and check_diagonal_win ,
    remove code leaving only the statement return false.*/
bool tic_tac_toe::check_diagonal_win()
{
    return false;
}



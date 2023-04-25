//h

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>

using std::ostream; using std::istream;
using std::cout; using std::cin;
using std::string; using std::vector;

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

//Homework 10 Update-- reordered due to error "-Wreorder"
class tic_tac_toe //abstract class
{
     protected:
        //Make class variable pegs a protected variable, and change it to std::vector<std::string> pegs;
        std::vector<std::string> pegs;
        //Make functions check_column_win, check_row_win, and check_diagonal_win protected virtual functions.
        virtual bool check_row_win();
        virtual bool check_column_win();
        virtual bool check_diagonal_win();
    
     private:
        void set_next_player();
        bool check_board_full();
        void clear_board();
        void set_winner();
        string winner;
        // Class
        string player;
        //vector<string> pegs{9, " "}; ***Removed for HW 9***
    
       //4. Modify the overloaded stream functions to work with TicTacToe 3 or 4
    friend std::ostream& operator<<(std::ostream& out, const tic_tac_toe& game); //overload out stream
    friend std::istream& operator>>(std::istream& in, tic_tac_toe& game); //overload in stream

    public:
        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player() const;
        string get_winner();
        //void display_board() const; ***Removed for HW 8***
        /*1. Create a constructor with an int parameter named size.
        a. in the constructor use an initializer list to initialize the vector to 9 or 16 elements
        HINT(multiply 3 or 4 by itself)
        Example: SomeConstructor(int s) :some_vector(s*s, " " ){}//this will initialize some_vector to s*s elements of " "*/
        tic_tac_toe(int size);
        /*Homework 10 Update a) Add class constructor in .h file 
        TicTacToe(std::vector<string> p, string win) //more code here to initialize the pegs vector with p and initialize winner.
        */
        tic_tac_toe(vector<string> p, string win);
        //Homework 10 Update b) Add const class function get_pegs that returns a vector of strings. return the pegs vector
        vector<string>get_pegs() const;

};

#endif

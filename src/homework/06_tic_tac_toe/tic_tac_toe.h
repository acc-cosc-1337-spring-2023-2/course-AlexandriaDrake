//h

#include<iostream>
#include<string>
#include<vector>

using std::ostream; using std::istream;
using std::cout; using std::cin;
using std::string; using std::vector;

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class tic_tac_toe //abstract class
{
    public:
        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player() const;
        string get_winner();
        //void display_board() const; ***Removed for HW 8***

    private:
        void set_next_player();
        bool check_board_full();
        void clear_board();
        bool check_row_win();
        bool check_column_win();
        bool check_diagonal_win();
        void set_winner();
        string winner;
        // Class
        string player;
        vector<string> pegs{9, " "};
    
    friend std::ostream& operator<<(std::ostream& out, const tic_tac_toe& game); //overload out stream
    friend std::istream& operator>>(std::istream& in, tic_tac_toe& game); //overload in stream
       
};

#endif

//cpp
#include "tic_tac_toe_data.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <fstream>

using std::getline; using std::make_unique;
using std::ifstream; using std::ofstream; 

void tic_tac_toe_data::save_games(const vector<unique_ptr<tic_tac_toe>>& games)
{
/*a) Add class function void save_games(const std::vector<std::unique_ptr<TicTacToe>>& games) 
Algorithm: Open file for writing*/
    ofstream save_file;
    save_file.open("saved_games.dat");
    
    
    for(const auto& game : games)
    {
        //For each vector of TicTacToe
        vector<string> pegs = game->get_pegs();
        //For each char in string 
        for (const string& s : pegs)
        {
            //Write char to file
            save_file << s;
        }
        //end char in string loop
  
        //Write get winner of game to file
        save_file<<game->get_winner();
        //Write a new line
        save_file<<"\n";
    }
    //end vector of TicTacToe loop 
    save_file.close();
}

vector<unique_ptr<tic_tac_toe>> tic_tac_toe_data::get_games()
{
    /*b) Add  std::vector<std::unique_ptr<TicTacToe>> get_games() function.
    Algorithm to restore a vector of unique ptr of TicTacToe from file.
    (Each line in the file is a game(vector of string), 
    each character in the line is the , and from left to right position 0,1, etc.). 
    The last character in each line is the game winner.*/
    vector<unique_ptr<tic_tac_toe>> games;
    string line;
    ifstream read_file;
    read_file.open("saved_games.dat");
    
    if(read_file.is_open())
    {
        while (getline(read_file, line)) 
        {
            vector<string> pegs;
            for(size_t i = 0; i < line.size() - 1; i++)
            {
                pegs.emplace_back(string(1, line[i]));
            }
            string winner(1, line.back());

            if (pegs.size() == 9)
            {
                games.push_back(make_unique<tic_tac_toe3>(pegs, winner));
            }
            else if (pegs.size() == 16)
            {
                games.push_back(make_unique<tic_tac_toe4>(pegs, winner));
            }
        }
        read_file.close();

    }

    else
    {
        cout<<"Error: The file is not able to be opened.\n";
    }

    return games;
}
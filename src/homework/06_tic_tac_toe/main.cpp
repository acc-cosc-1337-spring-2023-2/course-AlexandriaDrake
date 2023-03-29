#include<tic_tac_toe.h>
#include<iostream>

using std::cout; using std::cin; using std::string;

int main() 
{
    string first_player;
    cout << "First Player: choose X or O to start the game: ";
    cin >> first_player;
    tic_tac_toe game;
    game.start_game(first_player);

    return 0;
}
#include<tic_tac_toe.h>
#include<iostream>

using std::cout; using std::cin; using std::endl;

int main() 
{
    tic_tac_toe game;
    int position;
    string new_player;
    
    auto continue_playing = 'Y';
    
    do
    {
        cout << "Enter first player (X or O): ";
        cin >> new_player;

        game.start_game(new_player);

        while (!game.game_over())
        {
            cout << "Player " << game.get_player() << ", enter a position for spaces 1 through 9: ";            
            cin >> position;

            game.mark_board(position);
            game.display_board();
        }

        cout << "Game over!" << endl;
        cout << "Do you want to play again? Enter 'Y' for yes or any other key to exit: ";
        cin >> continue_playing;
       
    }
    while (continue_playing == 'Y' || continue_playing == 'y');
    return 0;
}

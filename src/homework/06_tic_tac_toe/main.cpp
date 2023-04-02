#include<tic_tac_toe.h>
#include<iostream>

using std::cout; using std::cin; using std::endl;

int main() 
{
    tic_tac_toe game;
    int position;
    string first_player;
    
    auto continue_playing = 'Y';
    
    do
    {
        while (first_player != "X" && first_player != "O")
		{
			cout<<"\nPlease enter X or O: ";
			cin>>first_player;
			if(first_player != "X" && first_player != "O")
			{
				cout<<"Please enter a valid input: "<<"\n";
			}
		}

        game.start_game(first_player);

        while (!game.game_over())
        {
            cout << "\nPlayer " << game.get_player() << ", enter a position for spaces 1 through 9: ";            
            cin >> position;

            game.mark_board(position);
            game.display_board();
        }

        cout << "\nGame over! The winner is player "<<game.get_winner()<<"!\n";
        cout << "\nDo you want to play again? Enter 'Y' for yes or any other key to exit: ";
        cin >> continue_playing;
       
    }
    while (continue_playing == 'Y' || continue_playing == 'y');
    return 0;
}
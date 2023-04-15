#include<tic_tac_toe.h>
#include<tic_tac_toe_3.h>
#include<tic_tac_toe_4.h>
#include<tic_tac_toe_manager.h>
#include<iostream>

using std::cout; using std::cin; using std::endl; using std::make_unique;

//1.   Allow users to choose between a tic tac toe 3 or 4 game.



     /*a)  Modify TicTacToe game (or whatever variable name you used), to unique_ptr to   
          TicTacToe. (An instance of TicTacToe3 or 4 will be created in the next step)
     b)  Prompt the user to play TicTacToe 3 or 4 (requires conditional to create correct instance) 
          In the conditional structure, Create an instance (make_unique) of TicTacToe3 or 4
      c) Remember to dereference game pointers, use *game;
      d)  Modify the TicTacToe manager save game function call
           to manager.save_game (*game);
      e) For TicTacToe variable, change .notation to -> operator.*/

int main() 
{
    tic_tac_toe_manager manager;
    unique_ptr<tic_tac_toe>game;
    int x, o, t;
    int size;
        
    auto continue_playing = 'Y';
    
    do
    {
        //1.   Allow users to choose between a tic tac toe 3 or 4 game.
         //b)  Prompt the user to play TicTacToe 3 or 4 (requires conditional to create correct instance) 
    
        while(true)
        {
            cout<<"Please choose Tic Tac Toe game size-- Enter 3 or 4: ";
            cin>>size;

            if (size == 3 || size == 4)
            {
                break;            
            }
            else
            {
                cout<<"Invalid game size. Please enter 3 or 4: ";
            }
        }

         // In the conditional structure, Create an instance (make_unique) of TicTacToe3 or 4
        if(size == 3)
        {
            game = make_unique<tic_tac_toe3>();
        }
        else
        {
            game = make_unique<tic_tac_toe4>();
        }

        string first_player;
        while (first_player != "X" && first_player != "O")
		{
			cout<<"\nPlease enter X or O: ";
			cin>>first_player;
            if(first_player == "x")
            {
                first_player = "X";
            }
            if(first_player == "o")
            {
                first_player = "O";
            }
			if(first_player == "X" || first_player == "O")
            {
                break;
            }
            else
			{
				cout<<"Please enter a valid player X or O: "<<"\n";
			}
		}

        game->start_game(first_player);

        //c) Remember to dereference game pointers, use *game;
        while (!game->game_over()) 
        {
           cin >> *game;
           cout << *game;
        } 

        cout << "\nGame over! The winner is player "<<game->get_winner()<<"!\n\n";

        manager.save_game(game);
        manager.get_winner_totals(x, o, t);

        cout<<"X wins: "<<x<<"\n";
        cout<<"O wins: "<<o<<"\n";
        cout<<"Ties: "<<t<<"\n";

        cout << "\nDo you want to play again? Enter 'Y' for yes or any other key to exit: ";
        cin >> continue_playing;
       
    }
    while (continue_playing == 'Y' || continue_playing == 'y');

    cout<<"\nThanks for playing! Here are the winning games and the players final scores: \n";
    cout<<"\n"<<manager<<"\n";
    manager.get_winner_totals(x, o, t);
    cout<<"X Wins: "<<x<<"\n";
    cout<<"O Wins: "<<o<<"\n";
    cout<<"Ties: "<<t<<"\n\n";

    return 0;
}
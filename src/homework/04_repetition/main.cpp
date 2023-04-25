//write include statements
#include"dna.h"
#include<iostream>
//write using statements

using std::cout; using std::cin;

int main() 	
{
    int option;

    do
    {
        cout<<"\nPlease select an option: \n";
		cout<<"Enter 1 for Factorial\n";
    	cout<<"Enter 2 for Greatest Common Divisor\n";
    	cout<<"Enter 3 to EXIT the program\n";
        cin>>option;

        switch(option)
        {
        case 1:
			int num;
            cout<<"\n You selected Factorial.\n\n";
            cout<<"Please enter an integer greater than zero: ";
            cin>>num;
            cout<<"The factorial of the number "<<num<<" is: "<<factorial(num)<<"\n\n";
            break;

        case 2:
			int num1;
			int num2;
            cout<<"\nYou selected Greatest Common Divisor.\n\n";
            cout<<"Please enter an integer greater than zero: ";
            cin>>num1;
            cout<<"Please enter another integer greater than zero: ";
            cin>>num2;
            cout<<"The Greatest Common Divisor of your numbers "<<num1<<", "<<num2<<" is: "<<gcd(num1, num2)<<"\n\n";
            break;

        case 3:
            char confirm;
            cout<<"\nYou chose to exit the program. Are you sure you would like to exit the program? Enter 'Y' for yes or 'N' for no: \n\n";
            cin>>confirm;
            if(confirm == 'Y' || confirm == 'y')
            {
                cout<<"Exiting the program. Thank you!\n\n";
            }
            else(confirm == 'N' || confirm == 'n');
            {
                option = 0;
            }
            break;

        default:
            {
                cout<<"Invalid selection. Please enter 'Y' to confirm and exit the program or 'N' to continue the program.";
            }
        }
    } 
    while (option != 3);
	return 0;
}
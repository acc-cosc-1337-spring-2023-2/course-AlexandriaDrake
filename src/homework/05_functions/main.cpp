
#include"func.h"
#include<iostream>

//write using statements

using std::string; using std::cout; using std::cin;

int main() 	
{
    int selection = 0;
	double temp_value = 0;
	string dna_string;
	string temp_dna_string;

    do
    {
		run_menu();
		cin>>selection;

        switch(selection)
        {
			case 1:
				cout<<"\nYou selected Get GC Content.\n\n";
				cout<<"Please enter a DNA String that you want analyzed: ";
				cin>>dna_string;
				temp_value = get_gc_content(dna_string);
				cout<<"\nThe GC Content of "<<dna_string<<" is: "<<temp_value*100<<"%.\n\n";
				break;

			case 2:
				cout<<"\nYou selected Get DNA Compliment.\n\n";
				cout<<"Please enter a DNA String that you want analyzed: ";
				cin>>dna_string;
				temp_dna_string = get_dna_complement(dna_string);
				cout<<"\nThe DNA Complement of "<<dna_string<<" is: "<<temp_dna_string<<".\n\n";
				break;

			case 3:
				char confirm;
				cout<<"\nYou chose to exit the program. Are you sure you would like to exit the program? Enter 'Y' for yes or 'N' for no: \n\n";
				cin>>confirm;
				if(confirm == 'Y' || confirm == 'y')
				{
					cout<<"\nExiting the program. Thank you!\n\n";
					selection++;
				}
				else(confirm == 'N' || confirm == 'n');
				{
					break;;
				}

			default:
				
				cout<<"Invalid selection. Please enter an option 1-3 from the menu: ";
				
        }
    } 
    while (selection != 4);
	return 0;
}
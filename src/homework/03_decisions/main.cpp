//write include statements
#include <decisions.h>
#include <iostream>

using std::string;
using std::cout;
using std::cin;

int main() 
{
	int grade = 0;
	int main_menu_option = 0;

	cout<<"\n MAIN MENU\n";
	cout<<"1- Letter grade using if\n";
	cout<<"2- Letter grade using switch\n";
	cout<<"3- Exit\n\n";
	cout<<"Enter a selection: \n";
	cin>>main_menu_option;

	if (main_menu_option == 1)
	{
		cout<<"Enter a grade: \n";
		cin>>grade;

		if(grade >= 0 && grade <=100)
		{
			auto result = get_letter_grade_using_if(grade);
			cout<<"The result using the if option is: "<<result<<"\n";
		
		}
		else
		{
			cout<<"The grade is not in range from 0 to 100.\n\n";
		}
	}
	else if (main_menu_option == 2)
	{
		cout<<"Enter a grade: \n";
		cin>>grade;

		if(grade >= 0 && grade <=100)
		{
			auto result = get_letter_grade_using_switch(grade);
			cout<<"The result using the switch option is: "<<result<<"\n";
		
		}
		else
		{
			cout<<"The grade is not in range from 0 to 100.\n\n";
		}
	}
	else if (main_menu_option == 3)
	{
		cout<<"Exiting the program. Thank you!\n\n";
	}
	else
	{
		cout<<main_menu_option<<" is an invalid selection.\n\n";
	}

	return 0;
}
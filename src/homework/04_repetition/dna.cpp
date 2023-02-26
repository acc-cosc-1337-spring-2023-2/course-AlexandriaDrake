//add include statements
#include "dna.h"
#include<iostream>

using std::cout; using std::cin; using std::swap;

//add function(s) code here

int factorial(int num)
{
    auto factorial = 1;

    while(num>0)
    {
        factorial *= num;
        num--;
    }

    return factorial;
}

int gcd(int num1, int num2)
{
   while(num1 != num2)
    {
        if(num1 < num2)
        {
            swap(num2, num1);
        }
        else if(num1>num2)
        {
            num1 = num1 - num2;
        }
    }
    return num1;
}


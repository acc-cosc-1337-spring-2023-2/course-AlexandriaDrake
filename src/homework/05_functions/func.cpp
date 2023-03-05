//add include statements

#include "func.h"
#include<iostream>

using std::cout;

//add function code here

double get_gc_content(const string& dna)
{
    int length = dna.length();
    double gc_count = 0;

    for (int num = 0; num < length; num++)
    {
        char count = dna[num];
        if (count == 'G' || count == 'C')
        {
            gc_count++;
        }
    }

    return gc_count / length;
}

string get_reverse_string(string dna)
{
    int length = dna.length();
    
    string reversed_dna= "";

    for (int num = 1; num <= length; num++)
    {
        reversed_dna += dna[length - num];
    }
   
    return reversed_dna;
}

string get_dna_complement(string dna)
{
    string complement = "";
    string dna_temp = get_reverse_string(dna);

    for (auto nucleotide : dna_temp)
    {
        char dna_complement;

        switch (nucleotide)
        {
            case 'A':
                dna_complement = 'T';
                break;
            case 'T':
                dna_complement = 'A';
                break;
            case 'C':
                dna_complement = 'G';
                break;
            case 'G':
                dna_complement = 'C';
                break;
            default:
                dna_complement = nucleotide;
        }
        complement += dna_complement;
    }
    return complement;
}

void run_menu()
{
    cout<<"\nDNA Analysis Program Menu: \n";
	cout<<"Enter 1 for Get GC Content.\n";
    cout<<"Enter 2 for Get DNA Complement.\n";
    cout<<"Enter 3 to EXIT the program.\n";
    cout<<"\nPlease select an option: ";
}
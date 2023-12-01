//!this is by Mr: Abu-Hadhoud 
#include <iostream>
#include <cctype>
#include <string>
using namespace std;
  
string ReadString(string prompt)
{
    string str;
    
    cout << prompt ;
    getline(cin , str);

    return str ;
}

char GetCharByUser(string prompt)
{
    char notion = 'c';

    cout << prompt;
    cin >> notion;

    return notion;
}
 
short CountLetterInString(char &c , string &str , bool matchCase = true)
{
    short count = 0 ; 
    
    for(int i = 0 ; i < str.length() ; ++i)
    {
        if(matchCase)
        {
            if(str.at(i) == c)
                count++ ;
        }
        else
        {
            if(toupper(str.at(i)) == toupper(c))
                count++ ;
        }
    }

    return count ;
}

char InvertLetterCase(char c)
{
    return isupper(c) ? tolower(c) : toupper(c);
}

void Project() 
{
    string str = ReadString("\nPlease Enter a String: \n");
    char c = GetCharByUser("\nPlease Enter a Letter to See it's repeatation: \n") ;
    
    cout << "\nLetter " << c << " Count " << CountLetterInString(c , str) << " time[s].\n";
    cout << "\nLetter '" << c << "' or '" << InvertLetterCase(c) << "' Count " << CountLetterInString(c , str , false) << " time[s].\n";
     
}

int main()
{
    Project();
}

//! this is by me 
/*
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

enum enWhatToCount{SmallLetters=0 , CapitalLetters=1 , All=3} ;
 
string ReadString(string prompt)
{
    string str;
    
    cout << prompt ;
    getline(cin , str);

    return str ;
}

char GetCharByUser(string prompt)
{
    char notion = 'c';

    cout << prompt;
    cin >> notion;

    return notion;
}
 
short CountLetterInString(char &c , string &str)
{
    short count = 0 ; 
    
    for(int i = 0 ; i < str.length() ; ++i)
    {
        if(str.at(i) == c)
            count++ ;
    }

    return count ;
}

void Project() 
{
    string str = ReadString("\nPlease Enter a String: \n");
    char c = GetCharByUser("\nPlease Enter a Letter to See it's repeatation: \n") ;
    char C ;
    isupper(c) ? C = tolower(c) : C = toupper(c) ; 
    cout << "\nLetter " << c << " Count " << CountLetterInString(c , str) << " time[s].\n";
    cout << "\nLetter '" << c << "' or '" << C << "' Count " << CountLetterInString(c , str) + CountLetterInString(C , str) << " time[s].\n";
     
}

int main()
{
    Project();
}
*/
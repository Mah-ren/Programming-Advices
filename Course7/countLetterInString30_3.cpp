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
    cout << "\nLetter " << c << " is repeated " << CountLetterInString(c , str) << " time[s].\n";
     
}

int main()
{
    Project();
}
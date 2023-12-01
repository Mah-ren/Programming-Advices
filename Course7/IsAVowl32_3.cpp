#include <iostream>
#include <cctype>
#include <string>
using namespace std;
  
char GetCharByUser(string prompt)
{
    char c = 'c';

    cout << prompt;
    cin >> c;

    return c;
}
  

bool isVowl(char &c)
{
    c = tolower(c) ;
    return  c == 'a' || c == 'e'|| c == 'i' || c == 'o' || c == 'u' ;
}

void Project() 
{
    char c = GetCharByUser("\nPlease Enter a Letter to See it's repeatation: \n") ;
 
    if(isVowl(c))
    {
        cout << "\nYes, Letter '" << c << "' is Vowl\n"; 
    }
    else
    {
       cout << "\nNo, Letter '" << c << "' is not Vowl.";
    }
}

int main()
{
    Project();
}

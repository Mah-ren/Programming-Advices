#include <iostream>
#include <string>
using namespace std;

string ReadString(string prompt)
{
    string str;
    
    cout << prompt ;
    getline(cin , str);

    return str ;
}

bool isUpperLetter(char c)
{
    return (static_cast<int>(c) >= 65 && static_cast<int>(c) <= 90) ;
} 

char InvertLetterCase(char c)
{
    return isUpperLetter(c) ? tolower(c) : toupper(c);
}

string InvertAllLettersCase(string &str)
{
    for(int i = 0 ; i < str.length() ; ++i)
    {
        str.at(i) = InvertLetterCase(str.at(i)) ;
    }

    return str ;
} 

int main()
{
    string str = ReadString("\nPlease Enter a String: \n");
    cout << InvertAllLettersCase(str) << endl ; 

}
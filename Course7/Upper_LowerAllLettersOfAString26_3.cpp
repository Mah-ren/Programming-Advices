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

string ConvertingStringToLower(string &str)
{
    for(short i = 0 ; i < str.length() ; ++i)
    {
        str.at(i) = tolower(str.at(i));
    }
    return str ;
}
 

void ConvertAllLettersToLower(string &str)
{ 
    cout << "\nAfter Converting all letters to lower: \n";
    str = ConvertingStringToLower(str);
    cout << str << endl ;
}

string ConvertingStringToUpper(string &str)
{
    for(short i = 0 ; i < str.length() ; ++i)
    { 
        str.at(i) = toupper(str.at(i));
    }
    return str ;
}
 
void ConvertAllLettersToUpper(string &str)
{
    cout << "\nAfter Converting all letters to upper: \n";
    
    str = ConvertingStringToUpper(str);
    cout << str << endl ;
}

int main()
{
    string str = ReadString("\nPlease Enter a String: \n");
    
    ConvertAllLettersToLower(str);
    ConvertAllLettersToUpper(str);
    
}
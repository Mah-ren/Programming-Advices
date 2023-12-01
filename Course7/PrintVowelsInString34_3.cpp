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

bool isVowl(char &c)
{
    c = tolower(c) ;
    return  c == 'a' || c == 'e'|| c == 'i' || c == 'o' || c == 'u' ;
}

void PrintVowelsLettersInString(string &str)
{
    cout << "\nvowels Letters in this string are: ";
    
    for(int i = 0 ; i < str.length() ; ++i)
    {
        if(isVowl(str.at(i)))
            cout << str.at(i) << " "  ;
    }
   
}

void Project() 
{
    string str = ReadString("\nPlease Enter String: \n");
    PrintVowelsLettersInString(str);
}

int main()
{
    Project();
} 
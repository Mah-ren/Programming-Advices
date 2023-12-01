#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPunctuation(char);
string GetStringInput(string);
string RemovePunctuationsInString(string & );

void Project()
{
    string originalString = GetStringInput("\nPlease Enter Original String:\n");
    cout << "\nOriginal String : \n" << originalString ;
    
    cout << "\nPunctuations Removed: \n" << RemovePunctuationsInString(originalString);
}

int main()   
{
    Project();
}




string GetStringInput(string prompt)
{
    string str;
    
    cout << prompt ;
    getline(cin , str);

    return str ;
}

string RemovePunctuationsInString(string &str)
{
    string s = "";
    for(short i = 0 ; i < str.length() ; ++i)
    {
        if(!isPunctuation(str[i]))
            s += str[i]; 
    }
    
    return s;
}

bool isPunctuation(char c)
{
     return (c == '!' || c == '"' || c == '#' || c == '$' || c == '%' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',' || c == '-' || c == '.' || c == '/' || c == ':' || c == ';' || c == '<' || c == '=' || c == '>' || c == '?' || c == '@' || c == '[' || c == '\\' || c == ']' || c == '^' || c == '_' || c == '`' || c == '{' || c == '|' || c == '}' || c == '~');
} 

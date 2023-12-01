#include <iostream>
#include <string>
using namespace std;

string GetStringInput(string prompt)
{
    string str;
    
    cout << prompt ;
    getline(cin , str);

    return str ;
}

string TrimLeft(string str , string delimiter=" ")
{    
    for(int i = 0 ; i < str.length() ; i++)
    {
        if(str.at(i) != ' ') 
            return str.substr(i, str.length() - i) ;
    }
    
    return "" ;
}
string TrimRight(string str , string delimiter=" ")
{    
    for(int i = str.length()-1 ; i >= 0 ; --i)
    {
        if(str.at(i) != ' ')
            return str.substr(0 , i+1) ;
    }
    
    return "" ;
}

string Trim(string str , string delimiter=" ")
{
    return TrimLeft(TrimRight(str));
}

void Project()
{
    string str = GetStringInput("\nPlease Enter String: \n") ;
    cout << "\nTrim Left:" << TrimLeft(str) << "*";
    cout << "\nTrim Left:" << TrimRight(str) << "*";
    cout << "\nTrim     :" << Trim(str) << "*";
}

int main()
{
    Project();
}
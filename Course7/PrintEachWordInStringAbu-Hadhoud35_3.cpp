#include <iostream>
#include <string>
using namespace std ;


string ReadString(string prompt)
{
    string str;
    
    cout << prompt ;
    getline(cin , str);

    return str ;
}

void PrintEachWordInString(string str)
{
    string delimeter = " " , word ;
    short position = 0 ; 
    while((position = str.find(delimeter)) != str.npos)
    {
        word = str.substr(0,position);
        if(word != "")
        {
            cout << word << endl ; 
        }
        str.erase(0, position+delimeter.length());
    }    
    if(str != "")
        cout << str << endl ; 
}

void Project()
{
    PrintEachWordInString(ReadString("\nPlease Enter String: \n"));

}

int main()
{
    Project() ;
}
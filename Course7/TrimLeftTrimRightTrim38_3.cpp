//todo this made me furious and disapointed so i'll do it with Abu=Hadhoud Way cuz it's easier 

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

string TrimLeft(string str , string delimeter)
{     
    short position = 0 ; 
    bool  isLetter = true ;

    while((position = str.find(delimeter)) != str.npos && isLetter )
    {
        str.erase(position , delimeter.length()); 
        isLetter = (str.at(0) == ' ' ? true : false ) ;
        
    }            
    
    return str ;
}

string TrimRight(string str, string delimiter)
{
    short position = 0;
    bool isLetter = true;

    while ((position = str.find(delimiter)) != str.npos && isLetter)
    {
        str.erase(position, delimiter.length());
        short lastChar = str.length(); // Update lastChar after erasing the substring
        isLetter = (str.at(lastChar-1) == ' ' ? true : false);
    }

    return str;
}

void Project()
{
    string str = GetStringInput("\nPlease Enter String: \n");
    string originalString = str ;
    cout << "\nOriginal String :" << originalString ;
    cout << "\nstr             :" << str ;
    cout << "\nTrim Right      :" << TrimRight(str, " ") <<".";
    cout << "\nOriginal String :" << originalString ;
    cout << "\nTrim Left       :" << TrimLeft(str, " ")             << ".";
    cout << "\nOriginal String :" << originalString ;
    cout << "\nstr             :" << str  ;
    


}

int main()
{
    Project();
}




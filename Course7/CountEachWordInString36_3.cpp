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
    
short CountEachWordInString(string str)
{
    short position = 0 , count = 0 ; 
    string delimeter = " " , word;
    
    while((position = str.find(delimeter)) != str.npos)
    {
        word = str.substr(0 , position);
        if(word != "")
        {
            ++count ;
        }
        str.erase(0 , position + delimeter.length());
    }

    if(str != "")
    {
        ++count ; 
    }
    return count ; 
}

void Project()
{
    cout << "\nThe Number of Words In Your String is: " << CountEachWordInString(ReadString("\nPlease Enter String: \n"));
}

int main()
{
    Project() ;
}
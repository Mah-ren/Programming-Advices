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

short CountVowelsInString(string &str)
{
    short count = 0 ;

    for(int i = 0 ; i < str.length() ; ++i)
    {
        if(isVowl(str.at(i)))
            count++;
    }

    return count ;
}

void Project() 
{
    string str = ReadString("\nPlease Enter String: \n");
    cout << "\nNumber of vowels in this string is: " << CountVowelsInString(str) << endl;
}

int main()
{
    Project();
}
//! please enter Your String: 
//! Mdfjdkfjkfjdkf

//!Number of vowels is: 14 
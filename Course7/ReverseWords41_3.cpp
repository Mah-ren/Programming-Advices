//! this is by me making newString

#include <iostream>
using namespace std;




string GetStringInput(string prompt)
{
    string str;
    
    cout << prompt ;
    getline(cin , str);

    return str ;
}


string ReverseWords(string str , string delimiter = " ")
{                                                              
    short position = 0 ;                                     
    string newString , word;                                   
      //! M a h m o u d   A h  m  e  d-> 
      //! 0 1 2 3 4 5 6 7 8 9 10 11 12 13        word = from "length = 13-1" to "7 + 1 "
    while((position = str.rfind(delimiter)) != str.npos)
    {    
        word = str.substr( position+1 , str.length()-1);
        newString += word  + delimiter ;
        str.erase(position+1 - delimiter.length() , str.length()-1);
    }   

    if(str != "")
        newString += str ;

    return newString ;
}

void Project()
{
    string str = GetStringInput("\nPlease Enter String: \n");
    cout << "\nLength of string:" << str.length();
    string newString =  ReverseWords(str , " ") ;
    cout << "\n\nString after reversing words: \n" << newString ;
    cout << "\nLength of new string:" << newString.length();
    cout << "\nOriginal String: \n" << str ;

}

int main()
{
    Project();
}
 
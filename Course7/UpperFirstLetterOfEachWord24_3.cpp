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

string UpperFirstLetterOfEachWord(string &str)
{
    bool isFirstLetter = true ; 
    
    for(short i = 0 ; i < str.length() ; ++i)
    {
        if(str.at(i) != ' ' && isFirstLetter)
        {
            str.at(i) = toupper(str.at(i)) ;
        }

        isFirstLetter = (str[i] == ' ' ? true : false);
    }
    
    return str ;
}
 

void ConvertFirstLetterOfWordToUpper()
{
    string str = ReadString("\nPlease Enter a String: \n");

    cout << "\nString After Conversion: \n";
    
    str = UpperFirstLetterOfEachWord(str);
    cout << str << endl ;


}

int main()
{
    ConvertFirstLetterOfWordToUpper();
}
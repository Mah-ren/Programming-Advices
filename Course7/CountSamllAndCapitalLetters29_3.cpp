#include <iostream>
#include <cctype>
#include <string>
using namespace std;

enum enWhatToCount{SmallLetters=0 , CapitalLetters=1 , All=3} ;

short GeneralFunctionForCountingLengthSmallCapitalLetters (string &str , enWhatToCount whatToCount=enWhatToCount::All)
{
    if(whatToCount == enWhatToCount::All)
        return str.length();

    short count = 0 ; 
    
    for (short i = 0; i < str.length(); i++)
    {
        if(whatToCount == enWhatToCount::CapitalLetters && isupper(str.at(i)))
            count++ ;
        else if(whatToCount == enWhatToCount::SmallLetters && islower(str.at(i)))
            count++ ;
    }

    return count ;
}

string ReadString(string prompt)
{
    string str;
    
    cout << prompt ;
    getline(cin , str);

    return str ;
}

short CountingUpperLettersInString(string &str)
{
    short upperLetters = 0 ;

    for(int i = 0 ; i < str.length() ; ++i)
    {
        if(isupper(str.at(i)))
            upperLetters++ ;
    }

    return upperLetters ;
}
short CountingLowerLettersInString(string &str)
{
    short lowerLetters = 0;

    for(int i = 0 ; i < str.length() ; ++i)
    {
        if(islower(str.at(i)))
            lowerLetters++ ;
    }

    return  lowerLetters ;
}

void Project()
{
    string str = ReadString("\nPlease Enter a String: \n");

    cout << "\n\nMethod1: \n\n" ;
    cout << "\nString Length is: " << str.length() ;
    cout << "\nCapital Letters Count: " << CountingUpperLettersInString(str) ;
    cout << "\nSmall Letters Count: " << CountingLowerLettersInString(str) ;

    cout << "\n\nMethod2: \n\n" ;
    cout << "\nString Length is: " << GeneralFunctionForCountingLengthSmallCapitalLetters(str) ;
    cout << "\nCapital Letters Count: " << GeneralFunctionForCountingLengthSmallCapitalLetters(str , enWhatToCount::CapitalLetters) ;
    cout << "\nSmall Letters Count: " << GeneralFunctionForCountingLengthSmallCapitalLetters(str , enWhatToCount::SmallLetters) ;


 
}

int main()
{
    Project();
}
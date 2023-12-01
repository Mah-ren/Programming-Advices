#include <iostream>
#include <vector>
#include <limits>
#include <string>
using namespace std ;

string  LowerAllString(string); 
string ConvertingStringToUpper(string); 
void SetScreenColor(bool , string , string );
vector<string> replaceTwoWords(vector<string> &vString , string , string , bool);
bool isWordFoundInVector(vector<string> &vString , string , bool);
string JoinString(vector<string> &vNames , string delimiter = " ");
string GetStringInput(string ) ;
vector<string> SplitString(string , string );
string ReplaceTwoWordsInStringWithSplit(string , string , string , bool);

void Project()
{
    string originalString , stringToReplace , sReplaceTo ;
   
    originalString = GetStringInput("\nPlease Enter Original String:\n");
    
    cout << "\nPlease Enter the word that you wanna change it and the word that you wanna change it to Respectivly: \n";
    cin >> stringToReplace >> sReplaceTo ;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    cout << "\nReplacing with Match Case:\n";
    cout << ReplaceTwoWordsInStringWithSplit(originalString , stringToReplace , sReplaceTo , true);
    cout << "\nReplacing without Match Case:\n";
    cout << ReplaceTwoWordsInStringWithSplit(originalString , stringToReplace , sReplaceTo , false);
} 

int main()
{
    Project();
}


//! /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string GetStringInput(string prompt)
{
    string str;
    
    cout << prompt ;
    getline(cin , str);

    return str ;
}

vector<string> SplitString(string str , string delimeter = " ")
{
    vector<string> vString ;
    string word ;
    short position = 0 ;
 
    while((position = str.find(delimeter)) != str.npos)
    {   
        word = str.substr(0,position);
        
        if(word != "")
        {
            vString.push_back(word);
        }
        
        str.erase(0 , position + delimeter.length());
    }

    if(str != "")
    {
        vString.push_back(str);
    } 

    return vString ;
}

string JoinString(vector<string> &vNames , string delimiter)
{
    string str ;
    
    for(const string &element : vNames)
    {                                    
        str += element + delimiter ;    
    }                                   
    return str.substr(0 , str.length()-delimiter.length()) ;
}

string ReplaceTwoWordsInStringWithSplit(string str , string stringToReplace , string sReplaceTo , bool matchCase)
{
    vector<string> vString ;
    vString = SplitString(str , " ");
    for(string &s : vString)
    {
        if(matchCase)
        {
            if(s == stringToReplace)
                s = sReplaceTo ;
        }
        else 
            if(LowerAllString(s) == LowerAllString(stringToReplace))
                s = sReplaceTo ;
    }

    return JoinString(vString , " ");
}
 
void SetScreenColor(bool rightAnswer  , string messageIfRightAnswer , string messageIfWrongAnswer)
{
    if(rightAnswer)    
    {
        cout << messageIfRightAnswer;
        system("color a0");
    }
    else 
    {
        cout << messageIfWrongAnswer;
        system("color c0");
    }
}
 
string  LowerAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)    
    {
        S1[i] = tolower(S1[i]);     
    }

    return S1; 
} 



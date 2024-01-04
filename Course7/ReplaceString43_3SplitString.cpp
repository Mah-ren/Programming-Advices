//! this way by storing the string in a vector and then join it again 
#include <iostream>
#include <vector>
#include <limits>
#include <string>
using namespace std ;
 
string ConvertingStringToUpper(string); 
vector<string> replaceTwoWords(vector<string> &vString , string , string , bool);
bool isWordFoundInVector(vector<string> &vString , string , bool);
string JoinString(vector<string> &vNames , string delimiter = " ");
string GetStringInput(string ) ;
vector<string> SplitString(string , string );
vector<string> ReplaceTwoWordsInString(string , string , string , bool);

void Project()
{
    string originalString , StringToReplace , sReplaceTo ;
   
    originalString = GetStringInput("\nPlease Enter Original String:\n");
    
    cout << "\nPlease Enter the word that you wanna change it and the word that you wanna change it to Respectivly: \n";
    cin >> StringToReplace >> sReplaceTo ;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    vector<string>vString = ReplaceTwoWordsInString(originalString , StringToReplace , sReplaceTo , false);
    cout << "\nReplacing with Match Case:\n";
    cout << JoinString( vString , " ");
    cout << "\nReplacing without Match Case:\n";
    vString = ReplaceTwoWordsInString(originalString , StringToReplace , sReplaceTo , true);
    cout << JoinString(vString , " ");
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

vector<string> ReplaceTwoWordsInString(string str , string StringToReplace , string sReplaceTo , bool CaseSensitive)
{
    vector<string> vString ;
    vString = SplitString(str , " ");
    
    if(isWordFoundInVector(vString , StringToReplace , CaseSensitive)) 
    {
        vString = replaceTwoWords(vString , StringToReplace , sReplaceTo , CaseSensitive);
        cout << "Replacing words done successfuly :-)\n";
        system("color 0f");
    }
    else 
    {
        cout << "No occurrence of the word " << StringToReplace;
        system("color 0c");
        system("pause");
    }
    return vString;
}

bool isWordFoundInVector(vector<string> &vString , string word , bool caseSensitive = false)
{
    if(!caseSensitive)
    {
        for(string &element : vString)
        {
            if(element == word)
                return true ;
        }
    }
    else 
    {
        for(string element : vString)
        {
            element = ConvertingStringToUpper(element);
            word    = ConvertingStringToUpper(word);
            if(element == word)
                return true ;
        }
    }
}

vector<string> replaceTwoWords(vector<string> &vString , string StringToReplace , string sReplaceTo , bool caseSensitive)
{
    string temp; 
    if(!caseSensitive)
    {    
        for(string &element : vString)
        {
            if(element == StringToReplace)
                element = sReplaceTo ; 
        }
    }
    else 
    {
        for(string &element : vString)
        {
            temp = ConvertingStringToUpper(element);
            StringToReplace  = ConvertingStringToUpper(StringToReplace);
            if(temp == StringToReplace)
                element = sReplaceTo;
        }
    }

    return vString;
}

string ConvertingStringToUpper(string str)
{
    for(short i = 0 ; i < str.length() ; ++i)
    { 
        str.at(i) = toupper(str.at(i));
    }
    return str ;
}
 
 



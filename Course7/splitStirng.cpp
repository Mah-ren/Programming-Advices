#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
string GetStringInput(string prompt)
{
    string str;
    
    cout << prompt ;
    getline(cin , str);

    return str ;
}

short CountWordsInString(string text , string delimiter)
{
    string word ; 
    short position = 0 , count = 0 ; 
    while(((position = text.find(delimiter)) != text.npos))
    {   
        word = text.substr(0 , position);
        if(word != "")
            count++ ;
        text.erase(0 , position + delimiter.length());
    }

    if(text != "")
        count++ ;

    return count ;
}

void FillVectorWithSplitString(vector<string> &vText , string &text , string &delimiter)
{
    short position = 0 ; 
    string word ;
    while((position = text.rfind(delimiter)) != text.npos)
    {
        word = text.substr(text.length() , position);
        if(word != "")
            vText.push_back(word);
        text.erase(text.length() , position + delimiter.length());
    }

    if(text != "")
        vText.push_back(word);
}

void PrintVector(vector<string> &vString , string delimiter)
{
    for(string &element : vString)
    {
        cout << element << delimiter;
    }

    cout << endl ;
}   

void Project()
{
    system("color 0f");
    system("color 0a");
    string text      = GetStringInput("\nPlease Enter Your Stirng: ") ;
    string delimiter = GetStringInput("\nPlease Enter Delimiter  : ") ;
    vector<string> vText ; 
    cout << "\nTokens       : [" << CountWordsInString(text , " ") << "] words " ;
    cout << "\nSplit String : \n" ;
    FillVectorWithSplitString(vText , text , delimiter);   
    PrintVector(vText , delimiter);     
}

int main()
{
    Project();
}


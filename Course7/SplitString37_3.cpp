//!this is by me
#include <iostream>
#include <vector>
#include <string>
using namespace std ;

string GetStringInput(string prompt)
{
    string str;
    
    cout << prompt ;
    getline(cin , str);

    return str ;
}

short CountEachWordInString(string str , string delimeter)
{
    short position = 0 , count = 0 ; 
    string word;

    while((position = str.find(delimeter)) != str.npos)
    {
        word = str.substr(0 , position);
        if(word != "")
        {
            count ++ ;
        }
        str.erase(0 , position + delimeter.length());
    }

    if(str != "")
    {
        count ++ ;
    }
     
    return count ;
}
 
void FillVectorWithWordsInString(string str , vector<string> &vString , string delimeter)
{
    short position = 0 ; 
    string word ;

    while((position = str.find(delimeter)) != str.npos)
    {
        word = str.substr(0 , position);
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
}

void PrintVector(vector<string> &vString)
{
    for(string &element : vString)
    {
        cout << element << "\n";
    }

    cout << endl ;
}   

void Project()
{
    string str = GetStringInput("\nPlease Enter String: \n");
    vector<string> vString ;
    cout << "\nTokens: " << CountEachWordInString(str , " ");
    FillVectorWithWordsInString(str , vString , " ");
    
    cout << "\nthis is from the vector:\n";
    PrintVector(vString);
}

int main()
{
    Project();
} 

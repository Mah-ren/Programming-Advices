//!this is by Abu-Hadhoud

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

void PrintVector(vector<string> &vString)
{
    cout << "\nThis is the elements of the vector: \n";

    for(string &element : vString)
    {
        cout << element << "\n";
    }

    cout << endl ;
}   

void Project()
{
    vector<string> vString ;
    vString = SplitString(GetStringInput("\nPlease Enter String: \n") , "#,,#") ; 
    cout << "\nTokens: " << vString.size();
    PrintVector(vString);
}

int main()
{
    Project();
} 

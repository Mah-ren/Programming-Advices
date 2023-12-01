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

string ReverseWords(string str , string delimiter = " ")
{
    vector<string> vString ; 
    string newString ;
    
    vString = SplitString(str , delimiter);

    vector<string>::iterator iter = vString.end();
    while(iter != vString.begin())
    {
        --iter ;
        newString += *iter + delimiter ;
    }

    return newString.substr(0 , newString.length()-delimiter.length()) ;
}

void Project()
{
    string str = GetStringInput("\nPleasemahmoudEnter String:\n");
    cout << "\nThis is The String after being Reversed: \n" << ReverseWords(str , " ");
}

int main()
{
    Project();
}
 
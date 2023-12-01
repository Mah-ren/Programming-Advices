#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPunctuation(char);
string JoinString(vector<string> &  , string);
vector<string> SplitString(string , string);
string GetStringInput(string);
string RemovePunctuationsInString(string & );

void Project()
{
    string originalString = GetStringInput("\nPlease Enter Original String:\n");
    cout << "\nOriginal String : \n" << originalString ;
    
    cout << "\nPunctuations Removed: \n" << RemovePunctuationsInString(originalString);
}

int main()   
{
    Project();
}




string GetStringInput(string prompt)
{
    string str;
    
    cout << prompt ;
    getline(cin , str);

    return str ;
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

string RemovePunctuationsInString(string &str)
{
    vector<string> vString ;
    vString = SplitString(str , " ");
        
    for(string &s : vString)
    {
        for(short i = 0 ; i < s.length() ; ++i)
        {
            if(isPunctuation(s[i]))
                s.erase(i , 1);
        }
    }

    return JoinString(vString , " ");
}

bool isPunctuation(char c)
{
     return (c == '!' || c == '"' || c == '#' || c == '$' || c == '%' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',' || c == '-' || c == '.' || c == '/' || c == ':' || c == ';' || c == '<' || c == '=' || c == '>' || c == '?' || c == '@' || c == '[' || c == '\\' || c == ']' || c == '^' || c == '_' || c == '`' || c == '{' || c == '|' || c == '}' || c == '~');
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

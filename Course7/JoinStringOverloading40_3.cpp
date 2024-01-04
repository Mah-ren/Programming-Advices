#include <iostream>
#include <vector>
#include <string>
using namespace std;


string JoinString(string array[] , short length , string delimiter = " ")
{
    
    string str ;
    for(int i = 0 ; i < length ; ++i)
        str += array[i] + delimiter ;

    return str.substr(0 , str.length()-delimiter.length());
}

string JoinString(vector<string> &vNames , string delimiter = " ")
{
    string text ;
    
    for(string &element : vNames)
        text += element + delimiter;
    return text.substr(0 , text.length()-delimiter.length()) ;
}

void Project()
{
    vector<string> vNames = {"mahmoud" , "ahmed" , "abdel aal" , "ahmed"};
    cout << "\nThis is Vector:" << JoinString(vNames , ",");
    
    string array[] = {"MAHMOUD" , "AHMED" , "ABDEL AAL" , "AHMED"} ;
    short length = sizeof(array)/sizeof(array[0]);
    cout << "\nThis is Array:" << JoinString(array , length , ",") ;
}

int main()
{
    Project();
}
 

























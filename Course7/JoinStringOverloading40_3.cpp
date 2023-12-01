#include <iostream>
#include <vector>
#include <string>
using namespace std;


string JoinString(string array[3] , short length , string delimiter = " ")
{
    
    string str ;
    for(int i = 0 ; i < length ; ++i)
    {
        str += array[i] + delimiter ;
    }

    return str.substr(0 , str.length()-delimiter.length());
}

string JoinString(vector<string> &vNames , string delimiter = " ")
{
    string str ;
    
    for(string &element : vNames)
    {                                   //!    this is by me don't need last line of code 
        str += element + delimiter ;    //!    if(vNames.empty())
                                        //!      return str ;
    }

    return str.substr(0 , str.length()-delimiter.length()) ;
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
 

























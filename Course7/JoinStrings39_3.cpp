#include <iostream>
#include <vector>
#include <string>
using namespace std;

string JoinStringFromVector(vector<string> &vNames , string delimiter = " ")
{
    string str ;
    
    for(string &element : vNames)
    {                                   //!    this is by me don't need last line of code 
        str += element ;                //!    if(vNames.empty())
        str += delimiter ;              //!    return str ;
    }

    return str.substr(0 , str.length()-delimiter.length()) ;
}

void Project()
{
    vector<string> vNames{"mahmoud" , "ahmed" , "abdel aal" , "ahmed"};
    cout << JoinStringFromVector(vNames);

}

int main()
{
    Project();
}
 

























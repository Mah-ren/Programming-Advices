#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> vNames {"mahmoud" , "ahmed" , "abdel aal"};

    for(string &name : vNames)
    {
        cout << name << endl ;
    }
    cout << "\nThe first Element of the vector: " << vNames.front();
    cout << "\nThe last Element of the vector: " << vNames.back() << endl ;

    vNames.erase(vNames.begin());

    cout << "\nI deleted the first element of the vector:\n";

    for(string &name : vNames)
    {
        cout << name << endl ;
    }

    cout << "\nI inserted Ali in the position of \"mahmoud\" \n" ;
    
    vNames.insert(vNames.begin() , "Ali");

    for(string &name : vNames)
    {
        cout << name << endl ;
    }


    
}
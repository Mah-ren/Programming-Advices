#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vNumbers{4,3,4,5,6};

    for(const int &i : vNumbers)
    {
        cout << i << " " ; 
    }
    
    cout << "\n\n";

    for(int &i : vNumbers)
    {
        i = 20 ;
    }

    for(int &i : vNumbers)
    {
        cout << i << " " ;
    }

    vector<int>::iterator iter ;

    for(iter = vNumbers.begin() ; iter != vNumbers.end() ; ++iter)
    {
        cout << *iter << " " ;
    }

    cout << "\nThis is index6: " << vNumbers[775] ;


}
#include <iostream>
 
#include <vector>
using namespace std;
 

 



void Project()
{   
    vector <int> vNumbers ;
    
    
vNumbers.push_back(10);
vNumbers.push_back(20);
vNumbers.push_back(30);
vNumbers.push_back(40);
vNumbers.push_back(50);
vNumbers.push_back(60); 
cout << "\nthe first element of the vector :  " << vNumbers.front();
cout << "\nthe first element of the vector :  " << vNumbers.back();
cout << "\n";
 
    for(int numbers : vNumbers)
    {
        cout << numbers << endl ;
    }
 
}


int main()
{
    Project();
}
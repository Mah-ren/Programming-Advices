#include <iostream>
using namespace std;

int main()
{
    void* ptr ; 
    short a = 10 ; 
    ptr = &a ; 

    cout << *(static_cast<short*>(ptr)) ;

    string name = "mahmoud";
    ptr = & name ;

    cout << *(static_cast<string*>(ptr));             

 


}
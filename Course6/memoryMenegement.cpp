#include <iostream>
using namespace std ; 



int main()
{
    void *ptr ; 
    
    ptr = new short ; 
    *(static_cast<short*>(ptr)) = 45 ; 
    cout << "\nThe value of pointer is: " << *(static_cast<short*>(ptr)) << endl ;

    delete  static_cast<short*>(ptr) ; 

}
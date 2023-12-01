#include <iostream>
using namespace std;

int main()
{
    int* pointer1 ; 
    float* pointer2 ;

    char notion  = 'c';
    
    if(notion == 'c')
    {

        pointer1 = new int ; 
        pointer2 = new float ; 

        *pointer1 = 34 ;
        *pointer2 = 33.5 ;

        cout << "\nThis is in if statement: \n";
        cout << "\npointer1: " << *pointer1 ;
        cout << "\npointer2: " << *pointer2 ;
    }

    delete pointer1 ;
    delete pointer2 ;

}
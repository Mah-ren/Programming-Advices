#include <iostream>
using namespace std;


void MyFunction()
{
    static int number = 1; 

    cout << "\nNumber 1 is: " << number ;
    
    number ++ ;
}


int main()
{
    MyFunction();
    MyFunction();
    MyFunction();
    MyFunction();
}
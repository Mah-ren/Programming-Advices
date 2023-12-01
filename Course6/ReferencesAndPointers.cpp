#include <iostream>
using namespace std;
for(int i = 0; i < length; i++)
{  
    cout << i << " " <<
}


void swap(int *a , int *b);

int main()
{
    int a = 10 ;
    int &x = a ;
    
    cout << "\na : " << a ;
    cout << "\nx : " << x ;

    cout << "\na address: " << &a ;
    cout << "\nx address: " << &x ;

    int* p = & a ;
    cout << "\nthe p " << p ;
    cout << "\nThe *p " << *p ;

    int b = 30 ;
    p = &b  ;
    
    cout << "\nthe address of b =  " << &b ;
    cout << "\nthe address of b with p  =  " << p ;
    cout << "\nthe value of p : " << *p ;

    cout << "\nBefore Swapping: \n" ;

    cout << "\na: " << a ;
    cout << "\nb: " << b ;

    cout << "\nAfter Swapping: \n" ;

    swap(&a, &b);

    cout << "\na: " << a ;
    cout << "\nb: " << b ;
}

void swap(int *a , int *b)
{
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}


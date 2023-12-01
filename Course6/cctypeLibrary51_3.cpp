#include <iostream>
using namespace std;


int main()
{
    char x = 'x' ;
    char y = 'y' ;
    char upperx = toupper('x'); 
    char uppery = toupper('y'); 

    cout << "\nx before the toupper library : " << x ; 
    cout << "\nx after the toupper library: " << upperx ;
    cout << "\ny before the toupper library : " << y ; 
    cout << "\ny after the toupper library: " << uppery ;

    char d = tolower(upperx);
    char w = tolower(uppery);


    cout << "\nThis is X after converting it to lower: " << d ;  
    cout << "\nThis is Y after converting it to lower: " << w ; 


    cout << "\nis x a lower letter: " << islower('A');
    cout << "\nis z an upper letter: " << isupper('z');

    cout << "\nis , a punctuation? " << ispunct(',');

}
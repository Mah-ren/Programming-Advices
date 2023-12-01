#include <iostream>
using namespace std;
void function1();

void function5()
{
    cout << "\nThis is in Function5";
}

void function4()
{
    function5();
    cout << "\nThis is in function4 ";
}

void function3()
{
    function4();
    cout << "\nThis is in function3 ";
}

void function2()
{
    function3();
    cout << "\nThis is in function2 ";
}

void function1()
{
    function2();
    cout << "\nthis is in function1";
}

int main()
{
    function1();
    cout << "\nthis is in main() ";
 
}




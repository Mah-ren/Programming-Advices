#include <iostream>
using namespace std;

void PrintNumbers(int min , int max)
{
    if(min <= max)
    {
        cout << min << "\n" ;
        PrintNumbers(min + 1 , max);
    }
}


int main()
{
    PrintNumbers(1,100000000);
    cout << "\nthis is in main() ";
 
}




#include <iostream>
using namespace std;



void function(short from, short to)
{
    if (from <= to)
    {
        cout << "\n" << from;
        function(from + 1, to);
    }
}

int main()
{
    function(1, 4);
}
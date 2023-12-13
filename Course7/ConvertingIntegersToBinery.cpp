#include <iostream>
#include <bitset>
using namespace std;


int main()
{
    int decimalValue = 10;

    short length = 1;
    cout << "\nenter length of numbers you want to know the binary of them: ";
    cin >> length;
    
    for(short i = 0; i < length; ++i)
    {
        cout << "\nenter the number[" << i + 1 << "]: ";
        cin >> decimalValue;

        bitset<8> binaryRepresentation(decimalValue);
        cout << "\nBinary Representation of: " << decimalValue << " is: " << binaryRepresentation << endl;
    }
}

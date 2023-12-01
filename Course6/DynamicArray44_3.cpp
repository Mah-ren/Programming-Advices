#include <iostream>
using namespace std;

int main()
{   
    int length ;
    cout << "\nPlease Enter The number of students: ";
    cin >> length ;

    float* pointer  ;

    pointer = new float[length] ;

    for(int i = 0 ; i < length ; ++i)
    {
        cout << "\nStudent[" << i+1 << "]: " ;
        cin >> *(pointer+i);
    }

    cout << "\nDisplaying The Results: \n";

    for(int j = 0 ; j < length ; ++j)
    {
        cout << "\nStudent[" << j+1 << "]: " << *(pointer + j);
    }

    delete[] pointer  ;

}
    
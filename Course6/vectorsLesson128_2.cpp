#include <iostream>
#include <vector>
using namespace std;



void PrintVectors(vector <int> &vNumbers)
{
    cout << "\nVectors Elements: \n\n";

    for( int &number : vNumbers)
    {
        cout<< number << endl ;
    } 
    cout << "\n";
}

void ReadVectors(vector <int> &vNumbers)
{
    int i = 0 ;
    char notice = 'c' ;
   
    do
    {
        cout << "\nPlease Enter Number: ";
        cin >> i ;
        vNumbers.push_back(i);
        cout << "If you want to add more elements, enter anything, else enter 'n' or 'N' : ";
        cin >> notice;
    } while (notice == 'Y' || notice == 'y');
   
    PrintVectors(vNumbers);
}

 



int main()
{
    vector <int> vNumbers ;
    ReadVectors(vNumbers);
  //PrintVectors(vNumbers);
}

 
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int GetValidPositiveNumberInRange(string prompt , int min , int max)
{
    int number = 1 ; 

    do
    {
        cout << prompt ;
        cin >> number ;
        
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            cout << "\nInvalid Input, Please Enter a Positive Integer from " << min << "-" << max << " : ";
            continue;
        }
    
    } while (number < min || number > max);
    return number ;
}


void PrintHyphen(int number)
{            
    if(number == 1)
        cout << "-------\n";
    else if(number == 2)
        cout << "-------------\n";
    else if(number == 3)
        cout << "-------------------\n";
    else if(number == 4)
        cout << "-------------------------\n";
    else if(number == 5)
        cout << "-------------------------------\n";
    else if(number == 6)
        cout << "-------------------------------------\n";
    else if(number == 7)
        cout << "-------------------------------------------\n";
    else if(number == 8)
        cout << "-------------------------------------------------\n";
    else if(number == 9)
        cout << "-------------------------------------------------------\n";
    else if(number == 10)
        cout << "-------------------------------------------------------------\n";
}

void FillMatrixWithOrderedNumbers(int array[100][100] , int length)
{
    for(int i = 0 ; i < length ; ++i)
    {
        for(int j = 0 ; j < length ; ++j)
            
        cout << "\n";
    }
}

void PrintOrderedMatrix(int array[100][100] , int length)
{
    for(int i = 0 ; i < length ; ++i)
    {
        PrintHyphen(3);

        for(int j = 0 ; j < length ; ++j)
            cout << setw(3) << right << array[i][j] << " " ;
        cout << "\n";
    }
}

void Project()
{
    int array[100][100], length ;
    length = GetValidPositiveNumberInRange("\nPlease Enter The Length of The Matrix: " , 1 , 20);
    PrintOrderedMatrix(array, length);
}

int main()
{
    Project();
}
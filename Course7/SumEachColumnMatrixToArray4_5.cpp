#include <iostream>
#include <limits>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;


int GetRandomNumberInRange(int min , int max)
{
    return rand() % (max - min +1) + min ;
}

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

void FillMatrixWithRandomNumbers(int array[100][100] , int &length)
{
    length = GetValidPositiveNumberInRange("\nPlease Enter How many Numbers: \n" , 1 , 100 );
    
    for(int i = 0 ; i < length ; ++i)
    {
        for(int j = 0 ; j < length ; ++j)
            array[i][j] = GetRandomNumberInRange(1,100);
    }
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

void PrintMatrix(int array[100][100] , int length)
{
    for(int i = 0 ; i < length ; ++i)
    {   
        PrintHyphen(length);
        cout << setw(1)  << left << "|" ;

        for(int j = 0 ; j < length ; ++j)
            cout << setw(4) << right <<  array[i][j] << " |";

        cout << "\n" ;
    }
   
    PrintHyphen(length);
}

int CalcSumOfOneColumn(int array[100][100] , short row , short column)
{
	int sum = 0 ;
	
	for(int j = 0 ; j < row ; ++j)
	{
		sum += array[j][column] ;
	}
	
	return sum ;
}

void FillArrayWithSumOfEachColumn( int array[100][100] , int length , int sum[50])
{    
    for(int i = 0 ; i < length ; i++)
        sum[i] = CalcSumOfOneColumn(array , length , i ) ;
};

void PrintArray(int Array[50] , int arrayLength)
{

    for(int i = 0 ; i < arrayLength ; i++)
    {
        cout << "___________________";
        cout << "\nColumn" << i+1 << " Sum: "<< Array[i] << "\n" ;
        PrintHyphen(3);
    }
    cout << "\n";
}
 
void Project()
{
    int array[100][100] , length ,  sum[50] ;
    FillMatrixWithRandomNumbers(array, length);
    cout << "\nThe Following is a " << length << "*" << length << " random Matrix: \n\n";
    PrintMatrix(array , length);
    cout << "\nThe Following is The Sum Of Each Column : \n" ;
    FillArrayWithSumOfEachColumn(array, length , sum);
    PrintArray(sum , length);
}
 
int main()
{
    Project();
}

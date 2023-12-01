#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;

enum enOpType{add = 1 , sub = 2 };


int GenerateRandomIntegerInRange(int min, int max)
{
    return rand() % (max - min + 1) + min ;
}


int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    char opType = 'c';
    short opType = 1;
    if(opType == enOpType::add)
        GenerateRandomIntegerInRange(1,2);        

    
}
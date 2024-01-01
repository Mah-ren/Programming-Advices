#include <iostream>
#include "classCalculator.h"
using namespace std;


int main()
{ 
    system("color 0f");
    system("cls");

    classCalculator Calculator;
    
    Calculator.Add(1);
    Calculator.PrintResult();
   
    Calculator.Add(111);
    Calculator.PrintResult();
   
    Calculator.Subtract(111);
    Calculator.PrintResult();
   
    Calculator.Multiply(111);
    Calculator.PrintResult();
   
    Calculator.Multiply(111);
    Calculator.PrintResult();
   
    Calculator.Clear();
    Calculator.PrintResult();
   
    Calculator.Add(100);
    Calculator.PrintResult();
   
    Calculator.Divide(20);
    Calculator.PrintResult();

    Calculator.Divide(0);
    Calculator.PrintResult();

    Calculator.CancelLastOperation();
    Calculator.PrintResult();
    
    Calculator.CancelLastOperation();
    Calculator.PrintResult();

    Calculator.GetFinalResult();
    Calculator.PrintResult();

    system("pause>0");
    return 0;
} 

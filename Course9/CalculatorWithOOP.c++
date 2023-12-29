#include <iostream>
using namespace std;

enum enOperations
{
    Add      = 1,
    Subtract = 2,
    Multiply = 3, 
    Division = 4, 
    Clear    = 5,
    CancelLastOperation = 6, 
    GetFinalResult      = 7, 

};
class classCalculator
{
private:
    double _lastNumber = 0;
    double _result = 0;
    double _previousResult = 0;
    enOperations _lastOperation;
    
    bool _isZero(double number)
    {
        return (number == 0);
    }

public:
    void Add(double number)
    {
        _lastNumber = number;
        _previousResult = _result;
        _result += number;
        _lastOperation = enOperations::Add;
    }
    void Subtract(double number)
    {
        _lastNumber = number;
        _previousResult = _result;
        _result -= number;
        _lastOperation = enOperations::Subtract;
    }
    void Multiply(double number)
    {
        _lastNumber = number;
        _previousResult = _result;
        _result *= number;
        _lastOperation = enOperations::Multiply;
    }
    void Divide(double number)
    {
        _lastNumber = number;

        if(_isZero(number))
            number = 1;
            
        _previousResult = _result;
        _result /= number;
        _lastOperation = enOperations::Division;
    }
    void Clear()
    {
        _lastNumber = 0;
        _previousResult = _result;
        _result = 0;
        _lastOperation = enOperations::Clear;
    }
    void CancelLastOperation()   
    { 
        _result = _previousResult;
        _lastOperation = enOperations::CancelLastOperation;
    }
    int GetFinalResult()
    {
        _lastOperation = enOperations::GetFinalResult;
        return _result; 
    }
    void PrintResult()
    {
        if(_lastOperation == enOperations::Add)
           cout << "\nResult After Adding " << _lastNumber << " is: " << _result; 
        else if(_lastOperation == enOperations::Subtract)
           cout << "\nResult After Subtracting " << _lastNumber << " is: " << _result; 
        else if(_lastOperation == enOperations::Multiply)
           cout << "\nResult After Multiplying " << _lastNumber << " is: " << _result; 
        else if(_lastOperation == enOperations::Division)
           cout << "\nResult After Dividing " << _lastNumber << " is: " << _result; 
        else if(_lastOperation == enOperations::Clear)
            cout << "\nResult After Clear " << _lastNumber << " is : " << _result;
        else if(_lastOperation == enOperations::CancelLastOperation)
            cout << "\nResult After Canceling Last Operation: " << _result;
        else if(_lastOperation == enOperations::GetFinalResult)
            cout << "\nFinal Result is: " << GetFinalResult();
    }
};

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

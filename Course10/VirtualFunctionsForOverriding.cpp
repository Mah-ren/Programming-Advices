#include <iostream>
using namespace std;


class classPerson
{
private:
    void PrivateFunction()
    {
        cout << "\nthis is a private function.";
    }
protected: 
    void ProtectedFunction()
    {
        cout << "\nThis is a protected function.";
    }
public: 
    virtual void PublicFunction()
    {
        cout << "\nThis is a public function.";
    }
};

class classEmployee : public classPerson
{
public:
    void PublicFunction()
    {
        cout << "\nEmployee.";
    }   
};
class classStudent : public classPerson
{
public: 
    void PublicFunction()
    {
        cout << "\nStudent.";
    }
};



int main()
{
    classPerson Person;
    Person.PublicFunction();

    classEmployee Employee;
    Employee.PublicFunction();


    classStudent Student;
    Student.PublicFunction();
    
    classPerson *Person1 = &Employee;
    classPerson *Person2 = &Student;

    Person1->PublicFunction();
    Person2->PublicFunction();

}
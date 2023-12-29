/*#include <iostream>
using namespace std;


class classPerson
{
public:
    classPerson()
    {
        cout << "\nHi, I'm Constructor";
    }
    ~classPerson()
    {
        cout << "\nHi, I'm Deconstructor";
    }
};

void Function()
{
    classPerson Person;
}

int main()
{
    //Function();
    classPerson *Person = new classPerson;
    delete Person;
}*/


#include <iostream>
#include <string>
using namespace std;


class clsPerson
{
private:
    string _name;
    static int _persons;

public:
    clsPerson()
    {
        _persons++;
    }
    void setPersonName(string name)
    {
        _name = name;
    }
    void printPersonName()
    {
        cout << _name << endl;
    }
    void printHowMuchPersons()
    {
        cout << "TOTAL PERSONS: " << _persons << endl;
    }
    static int canStaticMethodBeCalled()
    {
        return _persons;
    }
};

int clsPerson::_persons = 3;

int main()
{
    cout << clsPerson::canStaticMethodBeCalled();
}
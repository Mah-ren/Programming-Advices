#include <iostream>
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
    cout << "\nPerforming the deconstructor with system(\"pause > 0\"";
    classPerson Person;
    system("pause >0");

    Function();
    classPerson *Person2 = new classPerson;
    delete Person2;
}


// #include <iostream>
// #include <string>
// using namespace std;


// class clsPerson
// {
// private:
//     string _name;
//     static int _persons;

// public:
//     clsPerson()
//     {
//         _persons++;
//     }
//     void setPersonName(string name)
//     {
//         _name = name;
//     }
//     void printPersonName()
//     {
//         cout << _name << endl;
//     }
//     void printHowMuchPersons()
//     {
//         cout << "TOTAL PERSONS: " << _persons << endl;
//     }
//     static int canStaticMethodBeCalled()
//     {
//         return _persons;
//     }
// };

// int clsPerson::_persons = 3;

// int main()
// {
//     cout << clsPerson::canStaticMethodBeCalled();
// }
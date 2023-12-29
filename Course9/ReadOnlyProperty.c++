// #include <iostream>
// #include <string>
// using namespace std;

// class classPerson
// {
//     short _ID = 10;
//     string _FullName;

// public:

//     string getFullName()
//     {
//         return _FullName;
//     }

//     short getID()
//     {
//         return _ID;
//     }

// };

// int main()
// {
//     system("color 0f");
//     system("cls");
//     classPerson Person1; //~ , Person2, Person3;

//     cout << "\nThis is the ID: " << Person1.getID();
//     cout << "\nFull Name: " << Person1.getFullName();

// }
#include <iostream>
using namespace std;
class clsPerson
{
private:
    int _ID = 10;
    string _FirstName;
    string _LastName;

public: // Property Get, this is a read only property because we don’t have a set function

    int ID()
    {
        return _ID;
    } // Property Set

    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    } // Property Get
    string FirstName()
    {
        return _FirstName;
    } // Property Set
    void setLastName(string LastName)
    {
        _LastName = LastName;
    } // Property Get
    string LastName()
    {
        return _LastName;
    }
    string FullName()
    {
        return _FirstName + " " + _LastName;
    }
};
int main()
{
    clsPerson Person1;
    Person1.setFirstName("Mohammed");
    Person1.setLastName("Abu-Hadhoud");
     

    cout << "ID:" << Person1.ID() << endl;
    cout << "First Name:" << Person1.FirstName() << endl;
    cout << "Last Name:" << Person1.LastName() << endl;
    cout << "Full Name:" << Person1.FullName() << endl;
    system("pause>0");
    return 0;
}
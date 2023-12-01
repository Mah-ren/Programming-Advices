#include <iostream>
using namespace std;
class clsPerson
{
private:
    int _ID = 10;
    string _FullName;

public:

    void ID(int ID)
    {
        _ID = ID;
    }

    int ID()
    {
        return _ID;
    }

    void FullName(string FullName)
    {
        _FullName = FullName;
    }

    string FullName()
    {
        return _FullName;
    }
    


};

int main()
{ 
    clsPerson Person1;

    Person1.ID(999);
    Person1.FullName("Mahmoud Ahmed Ali");

    cout << "ID:" << Person1.ID() << endl;
    cout << "Full Name:" << Person1.FullName() << endl;
    system("pause>0");
    return 0;
} 

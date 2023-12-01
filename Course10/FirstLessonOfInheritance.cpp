#include <iostream>
#include <string>
using namespace std;


class classPerson
{
private:
    string _ID = "11129292";
    string _firstName;
    string _lastName;
    string _fullName;
    string _email;
    string _phoneNumber;

public:
    classPerson()
    {

    }
    classPerson(string ID, string firstName, string lastName, string email, string phoneNumber)
    {
        _ID          = ID;
        _firstName   = firstName;
        _lastName    = lastName;
        _email       = email;
        _phoneNumber = phoneNumber;
    }

    void Print()
    {
        cout << "\nInfo:"
             << "\n____________________________\n"
             << "\nID        : " << getID()
             << "\nFirst Name: " << getFirstName()
             << "\nlast Name : " << getLastName()
             << "\nFull Name : " << getFirstName() + " " + getLastName() 
             << "\nEmail     : " << getEmail()
             << "\nPhone     : " << getPhone()
             << "\n____________________________"
             << endl;
    }

    string getID()
    {
        return _ID;
    }
 
    void setFirstName(string firstName)
    {
        _firstName = firstName;
    }
    string getFirstName()
    {
        return _firstName;
    }
 
    void setLastName(string lastName)
    {
        _lastName = lastName;
    }
    string getLastName()
    {
        return _lastName;
    }
    
    void setPhone(string phoneNumber)
    {
        _phoneNumber = phoneNumber;
    }
    string getPhone()
    {
        return _phoneNumber;
    }
    
    void setEmail(string email)
    {
        _email = email;
    }
    string getEmail()
    {
        return _email;
    }

    void SendEmail()
    {
        cout << "\n\nThe Following Message sent successfully to email: " << _email 
             << "\nSubject: Hi " << _firstName << ", How are you? "
             << "\nBody:I am Muslim";
    }
    void SendSMS()
    {
        cout << "\n\nThe Following SMS sent successfully to Phone: " << _phoneNumber 
             << "\nSubject: Hi " << _firstName + " " + _lastName << ", How are you? "
             << "\nBody:I am Muslim";
    }

    ~classPerson()
    {
        cout << "\nHi, I'm Deconstructor";
    }
};

class classEmployee : public classPerson
{
private: 
    string _title;
    string _department;
    int    _salary;
    
public: 
    classEmployee(string ID, string firstName, string lastName, string email, string phoneNumber, string title, string department, int salary) 
    :classPerson(ID, firstName, lastName, email, phoneNumber)
    {
        _title      = title;
        _department = department;
        _salary     = salary;
    }
    
    void setTitile(string title)
    {
        _title = title;
    }
    string getTitle()
    {
        return _title;
    }
    
    void setDepartment(string department)
    {
        _department = department;
    }
    string getDepartment()
    {
        return _department;
    }
    
    void setSalary(int salary)
    {
        _salary = salary;
    }
    int getSalary()
    {
        return _salary;
    }
    void Print()
    {
        cout << "\nInfo:"
             << "\n____________________________\n"

             << "\nID        : " << getID()
             << "\nFirst Name: " << getFirstName()
             << "\nlast Name : " << getLastName()
             << "\nFull Name : " << getFirstName() + " " + getLastName() 
             << "\nEmail     : " << getEmail()
             << "\nPhone     : " << getPhone()
    
             << "\nTitle     : " << getTitle()
             << "\nDepartment: " << getDepartment()
             << "\nSalary    : " << getSalary()

             << "\n____________________________"
             << endl;
    }
    
};
class classProgrammer : public classEmployee
{
private:
    string _mainProgrammingLanguage;
public:
    classProgrammer(string ID, string firstName, string lastName, string email, string phoneNumber, string title, string department, int salary, string mainProgrammingLanguage) 
    :classEmployee(ID, firstName, lastName, email, phoneNumber, title, department, salary) 
    {
        _mainProgrammingLanguage = mainProgrammingLanguage;
    }

    void setMainProgrammingLanguage(string mainProgrammingLanguage)
    {
        _mainProgrammingLanguage = mainProgrammingLanguage;
    }
    string getMainProgrammingLanguage()
    {
        return _mainProgrammingLanguage;
    }
    
    void Print()
    {
        cout << "\nInfo:"
             << "\n____________________________\n"

             << "\nID                       : " << getID()
             << "\nFirst Name               : " << getFirstName()
             << "\nlast Name                : " << getLastName()
             << "\nFull Name                : " << getFirstName() + " " + getLastName() 
             << "\nEmail                    : " << getEmail()
             << "\nPhone                    : " << getPhone()
             << "\nTitle                    : " << getTitle()
             << "\nDepartment               : " << getDepartment()
             << "\nSalary                   : " << getSalary()

             << "\nMain Programming Langauge: " << getMainProgrammingLanguage()
             << "\n____________________________"
             << endl;
    }
};

void Function()
{
    classProgrammer Programmer("9999999", "Maher", "Fadi Ali", "om@gmail.,com", "01159340935", "CEO", "Programming", 5000, "C++");
    Programmer.setMainProgrammingLanguage("Python and C++");
    Programmer.Print();
     

  
}
int main()
{
    Function();
}


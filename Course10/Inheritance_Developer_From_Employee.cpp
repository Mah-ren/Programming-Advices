#include <iostream>
#include <string>
using namespace std;


class classPerson
{
private:
    string _ID;
    string _firstName;
    string _lastName;
    string _email;
    string _phoneNumber;

public:
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
             << "\nID        : " << _ID 
             << "\nFirst Name: " << _firstName
             << "\nlast Name : " << _lastName
             << "\nFull Name : " << _firstName + " " + _lastName
             << "\nEmail     : " << _email
             << "\nPhone     : " << _phoneNumber
             << "\n____________________________"
             << endl;
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
    string getID()
    {
        return _ID;
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
    int _salary;

public:
    classEmployee(string ID, string firstName, string lastName, string email, string phoneNumber, string title, string department, int salary) : classPerson(ID, firstName, lastName, email, phoneNumber)
    {
        _title       = title;
        _department  = department;
        _salary      = salary;
    }

    void Print()
    {
        cout << "\nInfo:"
             << "\n____________________________\n"
             << "\nID        : " << getID()
             << "\nFirst Name: " << getFirstName()
             << "\nlast Name : " << getLastName()
             << "\nFull Name : " << getFirstName() + " " + getLastName()
             << "\nTitle     : " << getTitle()
             << "\nDepartment: " << getDepartment()
             << "\nSalary    : " << getSalary()
             << "\nEmail     : " << getEmail()
             << "\nPhone     : " << getPhone()
             << "\n____________________________"
             << endl;
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
    ~classEmployee()
    {
        cout << "\nHi, I'm Deconstructor";
    }
};

class classDeveloper: public classEmployee
{
private: 
    string _mainProgrammingLanguage;
public:
    classDeveloper(string ID, string firstName, string lastName, string email, string phoneNumber, string title, string department, int salary, string mainProgrammingLanguage) : classEmployee(ID, firstName, lastName, email, phoneNumber,  title, department, salary)
    {
        _mainProgrammingLanguage = mainProgrammingLanguage;
    }

    string GetMainProgrammingLanguage()
    {
        return _mainProgrammingLanguage;
    }

    void Print()
    {
        cout << "\nInfo:"
             << "\n____________________________\n"
             << "\nID        : " << getID()
             << "\nFirst Name: " << getFirstName()
             << "\nlast Name : " << getLastName()
             << "\nFull Name : " << getFirstName() + " " + getLastName()
             << "\nTitle     : " << getTitle()
             << "\nDepartment: " << getDepartment()
             << "\nSalary    : " << getSalary()
             << "\nEmail     : " << getEmail()
             << "\nPhone     : " << getPhone()
             << "\nMain Programming Language: " << GetMainProgrammingLanguage()
             << "\n____________________________"
             << endl;
    }

};



void Function()
{
        //! classEmployee(string ID, string firstName, string lastName, string title, string department, int salary, string email, string phoneNumber)
    classEmployee Person1("30311292104553", "Mahmoud", "Ahmed Abdel aal Ahmed", "om20031129@gmail.com", "01159340935", "Engineer", "Degital Marketing", 5000);

    Person1.Print();
    
    Person1.SendSMS();
    Person1.SendEmail();

    //todo modifying the information of Person1;
    Person1.setFirstName("Hna");
    Person1.setLastName("Ali Abdel hafez Hasan Ali");
    Person1.setPhone("01150594655");
    Person1.setEmail("dr2223@gmail.org");
    Person1.setTitile("Doctor");
    Person1.setDepartment("Surgery");
    Person1.setSalary(4545);

    Person1.Print();

    Person1.SendEmail();
    Person1.SendSMS();



}
void Function2()
{
    classDeveloper Developer("30311292104553", "Mahmoud", "Ahmed", "om20031129@gmail.com", "01159340935", "Software Engineer", "Software Engineering", 50000, "C++");
    Developer.Print();
}

int main()
{
    Function();
    Function2();
}


#include <iostream>
using namespace std;


class classPerson
{
    virtual void WelComeMessage(string fullName) = 0;
    virtual void SendEmail(string email, string text) = 0;
    virtual void SendSMS(string phoneNumber, string text) = 0;
};

class classEmployee : public classPerson
{
private:
    string _fullName;
public:
    void WelComeMessage(string fullName)
    {
        _fullName = fullName;
        cout << "\nHello " << _fullName;

    }
    void SendEmail(string email, string text)
    {
        cout << "\n\nThis is email for " << email << " , Mr:"<< _fullName << endl << text;
    }
    void SendSMS(string phoneNumber, string text)
    {
        cout << "\n\nThis is SMS for " << phoneNumber << " , Mr:"<< _fullName << endl << text;
    }
};
class classStudent : public classPerson
{

};

int main()
{
    classEmployee Employee;
    Employee.WelComeMessage("Mahmoud Ahmed");
    Employee.SendEmail("om20031129@gmail.com", "we sent you this email :-)");
    Employee.SendSMS("01159340935", "i am happy that i waited until i finish this course (text)");


}
#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsPerson
{
private:
    string _firstName;
    string _lastName;
    string _email;
    string _phone;

public:
    clsPerson(string firstName, string lastName, string email, string phone)
    {
        _firstName = firstName;
        _lastName = lastName;
        _phone = phone;
        _email = email;
    }
    string FirstName()
    {
        return _firstName;
    }
    void FirstName(string firstName)
    {
        _firstName = firstName;
    }
    string LastName()
    {
        return _lastName;
    }
    void LastName(string lastName)
    {
        _lastName = lastName;
    }
    string Phone()
    {
        return _phone;
    }
    void Phone(string phone)
    {
        _phone = phone;
    }
    string Email()
    {
        return _email;
    }
    void Email(string email)
    {
        _email = email;
    }
    string FullName()
    {
        return _firstName + " " + _lastName;
    }
};
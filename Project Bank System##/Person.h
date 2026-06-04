#pragma once
#include <iostream>
#include <string>
#include <regex>
using namespace std;

class Person
{
private:
    string _Name;
    string _Phone;

public:
    Person(string name, string phone)
    {
        _Name = name;
        _Phone = phone;
    }

    Person() {}

    string GetName() { return _Name; }
    string GetPhone() { return _Phone; }

    void SetName(string name) { _Name = name; }
    void SetPhone(string phone) { _Phone = phone; }

    void Print()
    {
        cout << "Name: " << _Name << endl;
        cout << "Phone: " << _Phone << endl;
    }
};
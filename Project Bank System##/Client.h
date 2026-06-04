#pragma once
#include "Person.h"

class Client : public Person
{
private:
    string _AccountNumber;
    double _Balance;

public:
    Client(string name, string phone, string acc, double balance)
        : Person(name, phone)
    {
        _AccountNumber = acc;
        _Balance = balance;
    }

    Client() {}

    string GetAccountNumber() { return _AccountNumber; }
    double GetBalance() { return _Balance; }

    void SetBalance(double balance)
    {
        if (balance >= 0)
            _Balance = balance;
    }

    void Print()
    {
        Person::Print();
        cout << "Account: " << _AccountNumber << endl;
        cout << "Balance: " << _Balance << endl;
    }
};
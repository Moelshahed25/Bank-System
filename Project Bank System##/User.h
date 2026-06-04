#pragma once
#include <string>
using namespace std;

class User
{
public:
    enum Permissions
    {
        pAll = -1,
        pList = 1,
        pAdd = 2,
        pTransactions = 4
    };

private:
    string _Username;
    string _Password;
    int _Permissions;

public:
    User(string u, string p, int per)
    {
        _Username = u;
        _Password = p;
        _Permissions = per;
    }

    User() {}

    string GetUsername() { return _Username; }
    string GetPassword() { return _Password; }
    int GetPermissions() { return _Permissions; }

    bool HasPermission(int p)
    {
        if (_Permissions == pAll)
            return true;

        return (_Permissions & p) == p;
    }
};
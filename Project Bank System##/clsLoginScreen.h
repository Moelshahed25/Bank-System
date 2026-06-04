#pragma once
#include "clsScreen.h"
#include "UserService.h"

class clsLoginScreen : protected clsScreen
{
public:

    static User Show()
    {
        string username, password;

        system("cls");

        _DrawHeader("Login Screen");

        cout << "\nEnter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        return UserService::Login(username, password);
    }
};
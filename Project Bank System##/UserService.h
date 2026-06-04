#pragma once
#include "UserFileManager.h"

class UserService
{
public:

    static User Login(string username, string password)
    {
        vector<User> users = UserFileManager::GetAllUsers();

        for (User u : users)
        {
            if (u.GetUsername() == username && u.GetPassword() == password)
                return u;
        }

        throw runtime_error("Invalid login!");
    }

    static void AddUser()
    {
        string u, p;
        int per;

        cin >> u >> p >> per;

        vector<User> users = UserFileManager::GetAllUsers();

        for (User user : users)
        {
            if (user.GetUsername() == u)
            {
                cout << "Exists\n";
                return;
            }
        }

        UserFileManager::SaveUser(User(u, p, per));
    }
};
#pragma once
#include <fstream>
#include <vector>
#include "User.h"
#include "Utils.h"

class UserFileManager
{
public:

    static vector<User> GetAllUsers()
    {
        vector<User> users;
        ifstream file("Users.txt");

        string line;

        while (getline(file, line))
        {
            vector<string> parts = SplitString(line);

            if (parts.size() == 3)
            {
                users.push_back(User(
                    Trim(parts[0]),
                    Trim(parts[1]),
                    stoi(parts[2])
                ));
            }
        }

        return users;
    }

    static void SaveUser(User user)
    {
        ofstream file("Users.txt", ios::app);

        file << user.GetUsername() << "#"
            << user.GetPassword() << "#"
            << user.GetPermissions()
            << endl;
    }
};
#pragma once
#include <fstream>
#include <vector>
#include "Client.h"
#include "Utils.h"

class ClientFileManager
{
public:

    static vector<Client> GetAllClients()
    {
        vector<Client> clients;
        ifstream file("Clients.txt");

        string line;

        while (getline(file, line))
        {
            vector<string> parts = SplitString(line);

            if (parts.size() == 4)
            {
                clients.push_back(Client(
                    Trim(parts[0]),
                    Trim(parts[1]),
                    Trim(parts[2]),
                    stod(parts[3])
                ));
            }
        }

        return clients;
    }

    static void SaveClient(Client c)
    {
        ofstream file("Clients.txt", ios::app);

        file << c.GetName() << "#"
            << c.GetPhone() << "#"
            << c.GetAccountNumber() << "#"
            << c.GetBalance()
            << endl;
    }

    static void OverwriteClients(vector<Client> clients)
    {
        ofstream file("Clients.txt");

        for (Client c : clients)
        {
            file << c.GetName() << "#"
                << c.GetPhone() << "#"
                << c.GetAccountNumber() << "#"
                << c.GetBalance()
                << endl;
        }
    }
};
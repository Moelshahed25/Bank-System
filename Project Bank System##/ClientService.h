#pragma once
#include "ClientFileManager.h"

class ClientService
{
public:

    static void AddClient()
    {
        string name, phone, acc;
        double balance;

        cout << "Name: ";
        cin >> name;

        cout << "Phone: ";
        cin >> phone;

        cout << "Account: ";
        cin >> acc;

        vector<Client> clients = ClientFileManager::GetAllClients();

        for (Client c : clients)
        {
            if (c.GetAccountNumber() == acc)
            {
                cout << "Account exists!\n";
                return;
            }
        }

        cout << "Balance: ";
        cin >> balance;

        if (balance < 0)
        {
            cout << "Invalid balance!\n";
            return;
        }

        ClientFileManager::SaveClient(Client(name, phone, acc, balance));

        cout << "Client added successfully.\n";
    }

    static void DeleteClient()
    {
        string acc;

        cout << "Enter Account Number: ";
        cin >> acc;

        vector<Client> clients = ClientFileManager::GetAllClients();

        for (int i = 0; i < clients.size(); i++)
        {
            if (clients[i].GetAccountNumber() == acc)
            {
                clients.erase(clients.begin() + i);

                ClientFileManager::OverwriteClients(clients);

                cout << "Client deleted successfully.\n";
                return;
            }
        }

        cout << "Account not found!\n";
    }

    static void ListClients()
    {
        vector<Client> clients = ClientFileManager::GetAllClients();

        for (Client c : clients)
        {
            c.Print();
            cout << "----------\n";
        }
    }

    static void Deposit()
    {
        string acc;
        double amount;

        cout << "Account Number: ";
        cin >> acc;

        cout << "Amount: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount!\n";
            return;
        }

        vector<Client> clients = ClientFileManager::GetAllClients();

        for (Client& c : clients)
        {
            if (c.GetAccountNumber() == acc)
            {
                c.SetBalance(c.GetBalance() + amount);

                ClientFileManager::OverwriteClients(clients);

                cout << "Deposit completed successfully.\n";
                return;
            }
        }

        cout << "Account not found!\n";
    }

    static void Withdraw()
    {
        string acc;
        double amount;

        cout << "Account Number: ";
        cin >> acc;

        cout << "Amount: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount!\n";
            return;
        }

        vector<Client> clients = ClientFileManager::GetAllClients();

        for (Client& c : clients)
        {
            if (c.GetAccountNumber() == acc)
            {
                if (amount > c.GetBalance())
                {
                    cout << "Insufficient balance!\n";
                    return;
                }

                c.SetBalance(c.GetBalance() - amount);

                ClientFileManager::OverwriteClients(clients);

                cout << "Withdraw completed successfully.\n";
                return;
            }
        }

        cout << "Account not found!\n";
    }

    static void Transfer()
    {
        string senderAcc, receiverAcc;
        double amount;

        cout << "Sender Account Number: ";
        cin >> senderAcc;

        cout << "Receiver Account Number: ";
        cin >> receiverAcc;

        if (senderAcc == receiverAcc)
        {
            cout << "Cannot transfer to the same account!\n";
            return;
        }

        cout << "Amount: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount!\n";
            return;
        }

        vector<Client> clients = ClientFileManager::GetAllClients();

        Client* sender = nullptr;
        Client* receiver = nullptr;

        for (Client& c : clients)
        {
            if (c.GetAccountNumber() == senderAcc)
                sender = &c;

            if (c.GetAccountNumber() == receiverAcc)
                receiver = &c;
        }

        if (!sender)
        {
            cout << "Sender account not found!\n";
            return;
        }

        if (!receiver)
        {
            cout << "Receiver account not found!\n";
            return;
        }

        if (amount > sender->GetBalance())
        {
            cout << "Insufficient balance!\n";
            return;
        }

        sender->SetBalance(sender->GetBalance() - amount);
        receiver->SetBalance(receiver->GetBalance() + amount);

        ClientFileManager::OverwriteClients(clients);

        cout << "Transfer completed successfully.\n";
    }

    static void ConvertCurrency()
    {
        const double RATE = 50.0;

        int choice;
        double amount;

        cout << "\nCurrency Exchange\n";
        cout << "[1] EGP -> USD\n";
        cout << "[2] USD -> EGP\n";
        cout << "Choose: ";
        cin >> choice;

        cout << "Amount: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount!\n";
            return;
        }

        if (choice == 1)
        {
            double usd = amount / RATE;

            cout << amount << " EGP = "
                << usd << " USD\n";

            ofstream file("Currency.txt", ios::app);

            file << amount
                << " EGP -> "
                << usd
                << " USD\n";
        }
        else if (choice == 2)
        {
            double egp = amount * RATE;

            cout << amount << " USD = "
                << egp << " EGP\n";

            ofstream file("Currency.txt", ios::app);

            file << amount
                << " USD -> "
                << egp
                << " EGP\n";
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }
};
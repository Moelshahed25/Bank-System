#pragma once
#include "clsScreen.h"
#include "ClientService.h"

class clsMainScreen : protected clsScreen
{
private:

    static void _ShowMenu()
    {
        cout << "\n\t\tMain Menu\n";
        _DrawLine();

        cout << "[1] Show Client List.\n";
        cout << "[2] Add New Client.\n";
        cout << "[3] Delete Client.\n";
        cout << "[4] Deposit.\n";
        cout << "[5] Withdraw.\n";
        cout << "[6] Transfer.\n";
        cout << "[7] Currency Exchange.\n";
        cout << "[8] Logout.\n";

        _DrawLine();
    }

public:

    static void Show(User user)
    {
        int choice;

        do
        {
            system("cls");

            _DrawHeader("Main Screen");

            cout << "User: " << user.GetUsername() << endl;

            _ShowMenu();

            cout << "\nChoose: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                ClientService::ListClients();
                break;

            case 2:
                ClientService::AddClient();
                break;

            case 3:
                ClientService::DeleteClient();
                break;

            case 4:
                ClientService::Deposit();
                break;

            case 5:
                ClientService::Withdraw();
                break;

            case 6:
                ClientService::Transfer();
                break;

            case 7:
                ClientService::ConvertCurrency();
                break;
            }

            system("pause");

        } while (choice != 8);
    }
};
#include "clsLoginScreen.h"
#include "clsMainScreen.h"

int main()
{
    while (true)
    {
        try
        {
            User user = clsLoginScreen::Show();

            clsMainScreen::Show(user);
        }
        catch (...)
        {
            cout << "Login Failed!\n";
            system("pause");
        }
    }
}
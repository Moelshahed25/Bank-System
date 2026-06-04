#pragma once
#include <iostream>
using namespace std;

class clsScreen
{
protected:

    static void _DrawLine(int width = 50)
    {
        for (int i = 0; i < width; i++)
            cout << "=";
        cout << endl;
    }

    static void _PrintCenter(string text, int width = 50)
    {
        int padding = (width - text.length()) / 2;

        for (int i = 0; i < padding; i++)
            cout << " ";

        cout << text << endl;
    }

    static void _DrawHeader(string title)
    {
        _DrawLine();
        _PrintCenter(title);
        _DrawLine();
    }
};
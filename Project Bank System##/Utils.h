#pragma once
#include <vector>
#include <string>
using namespace std;

static vector<string> SplitString(string line, char delimiter = '#')
{
    vector<string> parts;
    string word = "";

    for (char c : line)
    {
        if (c != delimiter)
            word += c;
        else
        {
            parts.push_back(word);
            word = "";
        }
    }

    if (word != "")
        parts.push_back(word);

    return parts;
}

static string Trim(string s)
{
    while (!s.empty() && s.back() == ' ') s.pop_back();
    while (!s.empty() && s.front() == ' ') s.erase(s.begin());
    return s;
}
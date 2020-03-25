#include <iostream>

using namespace std;

int main()
{
    string empty_str = "", str = "";
    while (cin >> str)
    {
        if (str.length() > empty_str.length())
            empty_str = str;
    }
    cout << empty_str;
}
 /* string s = "";
    getline(cin, s);
    int size_s = s.length(), counter = 0;
    vector <int> a(size_s + 1, 0);
    for (int i = 0; i < size_s; ++i)
    {
    if (s[i] == ' ' || i == size_s - 1)
    {
    s[i] == ' ' ? a[i] = counter : a[i + 1] = ++counter;
    counter = 0;
    } else
    ++counter;
    }
    int max_s = a[0], index = 0;
    for (int i = 1; i < size_s + 1; ++i)
    {
    if (max_s < a[i])
    {
    index = i;
    max_s = a[i];
    }
    }
    cout << s.substr(index - a[index], a[index]);
    return 0;

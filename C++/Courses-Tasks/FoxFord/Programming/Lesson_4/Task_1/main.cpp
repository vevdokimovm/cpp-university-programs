#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s.size() >= 5)
    {
        if (s[0] >= 'A' && s[0] <= 'Z' && s[2] >= '0' && s[2] <= '9' && s[3] >= '0' && s[3] <= '9')
        {
            if (s[1] >= 'A' && s[1] <= 'Z' && s.size() == 5 && s[4] >= '0' && s[4] <= '9')
            {
                cout << 2;
            }
            else if (s[1] >= 'A' && s[1] <= 'Z' && s[4] >= '0' && s[4] <= '9' && s[5] >= '0' && s[5] <= '9')
            {
                cout << 3;
            }
            else if (s[1] >= '0' && s[1] <= '9' && s[4] >= 'A' && s[4] <= 'Z' && s[5] >= 'A' && s[5] <= 'Z')
            {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
        else if (s[0] >= '0' && s[0] <= '9' && s[5] >= 'A' && s[5] <= 'Z' && s[1] >= '0' && s[1] <= '9' && s[2] >= '0' && s[2] <= '9' && s[3] >= '0' && s[3] <= '9' && s[4] >= 'A' && s[4] <= 'Z')
            {
                cout << 4;
            }
            else
            {
                cout << 0;
            }
    }
    else
    {
        cout << 0;
    }
    return 0;
}

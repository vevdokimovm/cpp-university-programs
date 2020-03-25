#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string s;
    short k = 0, ans = 0;
    cin >> s;
    short len = s.size();
    for (short i = 1; i < len; i++)
    {
        if (s[i] == '1')
        {
            ans += (1 << (len - (i + 1)));
        }
    }
    short sign = (1 << (len - 1));
    if (s[0] == '1')
    {
        ans -= sign;
    }
    cout << ans << endl;
    return 0;
}

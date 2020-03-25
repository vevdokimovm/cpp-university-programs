#include<iostream>
using namespace std;

int main()
{
    string  S;
    int d = 0, i;
    cin >> S;
    for (i = 0; i < S.size() ; ++i)
    {
        d <<= 1;
        d += (S[i] - '0');
    }
    if (S[0] == '0')
        cout << d;
    else
        cout << d - (1 << S.size());
    cout << endl;
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int i = 1, now, sum = 0;
    cin >> now;
    while (i != 0)
    {
        i = now;
        sum = sum + 1;
        cin >> now;
    }
    cout << sum-1 << endl;
    return 0;
}


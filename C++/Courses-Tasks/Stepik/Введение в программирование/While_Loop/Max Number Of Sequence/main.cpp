#include <iostream>

using namespace std;

int main()
{
    int max = 0, now;
    cin >> now;
    while (now != 0)
    {
        if (now > max)
        {
            max = now;
        }
        cin >> now;
    }
    cout << max << endl;
    return 0;
}

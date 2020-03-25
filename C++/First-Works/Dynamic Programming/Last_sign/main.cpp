#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    short n = 0;
    cin >> n;
    int a[1000] = {1, 1};
    for (int i = 2; i < n + 1; ++i)
        a[i] = (a[i - 1] + a[i - 2]) % 10;
    cout << a[n];
    return 0;
}

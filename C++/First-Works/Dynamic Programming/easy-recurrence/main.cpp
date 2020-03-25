#include <iostream>

using ull = unsigned long long;
using namespace std;

int main()
{
    unsigned n = 0;
    cin >> n;
    ull a[n + 1] = {1, 1};
    for (size_t i = 2; i < n + 1; ++i)
        i % 2 == 0 ? a[i] = a[i / 2] + a[i / 2 - 1] : a[i] = a[(i - 1) / 2] - a[(i - 1) / 2 - 1];
    cout << a[n] << endl;
    return 0;
}

#include <iostream>

using namespace std;
using ull = unsigned long long;
int main()
{
    unsigned c = 0;
    cin >> c;
    ull a[c + 1] = {1, 1};
    for (size_t n = 2; n < c + 1; ++n)
        n % 2 == 0 ? a[n] = a[n / 2] + 1 : a[n] = ((n + 1) / 2)[a] + 1 + (n / 2)[a];
    cout << a[c];
    return 0;
}

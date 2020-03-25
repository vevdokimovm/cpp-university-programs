#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull square(ull x) { return x * x; }

bool is_even(ull n){
    return (remainder(n, 2) == 0);
}

ull power(ull b, ull n){
    if (n == 0) return 1;
    else if (is_even(n))
        return square(power(b, n / 2));
    else
        return (b * power(b, n - 1));
}

int main()
{
    ull b = 0;
    ull n = 0;
    cin >> b >> n;
    cout << power(b, n);
    return 0;
}

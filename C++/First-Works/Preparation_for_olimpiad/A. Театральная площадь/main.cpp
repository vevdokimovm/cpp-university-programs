#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    long long n, m, a;
    cin >> n >> m >> a;
    cout << setprecision(0) << fixed << (ceil((double)n / a)) * (ceil((double)m / a));
    return 0;
}

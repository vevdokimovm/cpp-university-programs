#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n, m, l;
    cin >> n >> m;
    l = pow(2, n);
    cout << m % l << endl;
    return 0;
}

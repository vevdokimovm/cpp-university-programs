#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b = 2.3;
    cin >> a;
    b = floor(a);
    cout << abs(b-a) << endl;
    return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, r;
    cin >> a;
    b = floor(a);
    r = (a-b)*10;
    cout << trunc(r) <<  endl;
    return 0;
}

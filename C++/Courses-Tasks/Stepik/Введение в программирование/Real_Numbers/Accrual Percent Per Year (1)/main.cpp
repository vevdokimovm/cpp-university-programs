#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int p, x, y, x1, y1, b;
    cin >> p >> x >> y;
    int sum;
    double total;
    sum = x * 100 + y;
    total = sum * ((double)p/100 + 1);
    b = trunc(total);
    x1 = b/100;
    y1 = b - x1*100;
    cout << x1 <<" "<< y1;
    return 0;
}

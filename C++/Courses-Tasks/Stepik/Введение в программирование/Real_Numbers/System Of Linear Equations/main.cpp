#include <iostream>

using namespace std;

int main()
{
    double a, b, c, d, e, f, x, y;
    cin >> a >> b >> c >> d >> e >> f;
    if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)
    {
        x = 0;
        y = 0;
    }
    else
    {
        y = (c*e - a*f)/(b*c - d*a);
        x = ((e - b*y) / a);
    }
    cout << x <<" "<< y << endl;
    return 0;
}

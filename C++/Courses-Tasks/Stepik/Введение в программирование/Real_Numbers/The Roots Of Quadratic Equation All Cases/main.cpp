#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    double a, b, c, x, x1, D, D_2;
    cout << "If your equation look like that : ax^2 +- bx +- c = 0, so write down a  b  c " << endl;
    cin >> a >> b >> c;
    D = b*b - 4 * a * c;
    if (a == 0 && b == 0 && c == 0 )
    {
        cout << "Infinity of roots";
        exit(0);
    }
    if (a == 0 && b == 0 && c != 0)
    {
        cout << "Roots don't exist";
        exit(0);
    }
    if (a == 0 && b != 0)
    {
        cout << 1 <<" : "<< -c/b ;
        exit(0);
    }
    if (D < 0)
    {
        cout << "Roots don't exist";
    }
    else if (D == 0)
    {
        x = -b / (2*a);
        cout << 1 <<" : "<< x;
    }
    else if (D > 0)
    {
        D_2 = sqrt(D);
        x = (-b + D_2) / (2*a);
        x1 = (-b - D_2) / (2*a);
        if (x > x1)
        {
            cout << 2 <<" : "<< x1 <<" "<< x;
        }
        else
        {
            cout << 2 <<" : "<< x << " " << x1;
        }
    }
    return 0;
}

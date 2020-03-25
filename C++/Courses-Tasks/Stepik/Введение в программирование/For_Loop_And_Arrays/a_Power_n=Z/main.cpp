#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, power, count ;
    cin >> a >> power ;
    int a_1 = a;
    for (count = 1; count < power; count++)
    {
        a = a * a_1;
    }
    for (count = -1; power < count; count--)
    {
        a = a*a_1;
    }
    if (power==0)
        {
            cout << 1;
        }
    if (power > 0)
    {
        cout << a ;
    }
    if (power < 0)
    {
        cout << 1/(double)a;
    }
    return 0;
}

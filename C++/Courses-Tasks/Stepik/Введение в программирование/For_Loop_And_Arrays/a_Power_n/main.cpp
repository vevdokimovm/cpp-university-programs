#include <iostream>

using namespace std;

int main()
{
    int a, power, count;
    cin >> a >> power ;
    int a_1 = a;
    for (count=1; count < power; count++)
    {
        a = a * a_1;
    }
    cout << a << endl;
    return 0;
}

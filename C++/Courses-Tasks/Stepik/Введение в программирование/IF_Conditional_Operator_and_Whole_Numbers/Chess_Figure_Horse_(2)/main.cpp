#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x, y, x1, y1;
    cout << "Write down x y x1 y1" << endl;
    cin >> x >> y >> x1 >> y1;
    int distance_x = abs(x-x1);
    int distance_y = abs(y-y1);
    if ((distance_x==1 && distance_y == 2) || ((distance_x==2 && distance_y == 1)))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}

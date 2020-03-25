#include <iostream>
#include <triangle.h>

using namespace std;

int main()
{
    triangle h;
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    h.set_points(x1, y1, x2, y2, x3, y3);
    cout << (h.existence() ? "NO" : "YES") << " ";
    h.sides();
    h.area();
    return 0;
}

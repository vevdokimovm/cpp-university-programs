#include <iostream>

using namespace std;

bool IsPointArea(double x, double y){
    double value_straight_1 = -x;
    double value_straight_2 = 2 * x + 2;
    double value_circle = (x + 1) * (x + 1) + (y - 1) * (y - 1);
    if (value_circle <= 4 && y >= value_straight_1 && y >= value_straight_2)
        return 1;
    else if ((value_circle == 4 || value_circle > 4) && y <= value_straight_1 && y <= value_straight_2)
        return 1;
    else
        return 0;
}

int main()
{
    double x = 0;
    double y = 0;
    cin >> x >> y;
    cout << (IsPointArea(x, y) ? "YES" : "NO");
    return 0;
}

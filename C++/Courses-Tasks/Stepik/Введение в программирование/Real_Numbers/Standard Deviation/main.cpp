#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int now, count = 0, sum = 0 , sum_x2 = 0;
    double u;
    cin >> now;
    while (now != 0)
    {
        sum = sum + now;
        sum_x2 = sum_x2 + now*now;
        count++;
        cin >> now;
    }
    u = sqrt((sum_x2 - ((double)sum*sum/count))/(count - 1));
    cout << setprecision (6) << fixed;
    cout << u << endl;
    return 0;
}

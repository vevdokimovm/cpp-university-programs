#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int now, sum = 0, count = 0;
    double average;
    cin >> now;
    while (now != 0)
    {
        sum = sum + now;
        count++;
        cin >> now;
    }
    average = (double)sum / count;
    cout << setprecision(6) << fixed;
    cout << average << endl;
    return 0;
}

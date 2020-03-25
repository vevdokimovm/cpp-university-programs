#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class point
{
private:
    int x1, y1;
public:
    void set_points(int, int);
};

void point::set_points(int a, int b)
{
    x1 = a;
    y1 = b;
}

int main()
{
    vector <point> h(2);
    for (int i = 0; i < 2; i++)
    {
        int x1, y1;
        cin >> x1 >> y1;
        h[i].set_points(x1, y1);
    }
    cout << sqrt(h[0])
    return 0;
}

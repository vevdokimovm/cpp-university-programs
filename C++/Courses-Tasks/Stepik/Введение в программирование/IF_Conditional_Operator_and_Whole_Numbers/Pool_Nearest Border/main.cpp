#include <iostream>

using namespace std;

int main()
{
    int a, b, x, y;
    cout << "Write down a b x y" << endl;
    cin >> a >> b >> x >> y;
    int the_less_side_x;
    int the_less_side_y;
    if (a>b)
    {
        a = a;
    }
    else
    {
        swap(a,b);
    }
    int second_side_x = b - x;
    int second_side_y = a - y;
    if (x>second_side_x)
    {
        the_less_side_x = second_side_x;
    }
    else
    {
        the_less_side_x = x;
    }
    if (y>second_side_y)
    {
        the_less_side_y = second_side_y;
    }
    else
    {
        the_less_side_y = y;
    }
    if (the_less_side_y > the_less_side_x)
    {
        cout << the_less_side_x << endl;
    }
    else
    {
        cout << the_less_side_y << endl;
    }
    return 0;
}

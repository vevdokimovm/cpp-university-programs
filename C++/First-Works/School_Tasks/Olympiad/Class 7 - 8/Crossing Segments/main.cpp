#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a_end, a_start, b_end, b_start, cross;
    cout << "Write down a_end a_start b_end b_start" << endl;
    cin >> a_end >>  a_start >> b_end >> b_start;
    if (a_start > a_end)
    {
         swap(a_end,a_start);
    }
    if (b_start > b_end)
    {
        swap(b_end,b_start);
    }
    if (( a_start <= b_end && a_end >= b_start) && (a_end > b_end && a_start > b_start))
    {
        cross = b_end - a_start + 1;
        cout << cross;
    }
    else if ((a_end >= b_end && a_start <= b_start) && ( a_start <= b_end && a_end >= b_start))
    {
        cross = b_end - b_start + 1;
        cout << cross;
    }
    else if ((a_end < b_end && a_start < b_start) && ( a_start <= b_end && a_end >= b_start))
    {
        cross = a_end - b_start + 1;
        cout << cross;
    }
    else if ((a_end <= b_end && a_start >= b_start) && ( a_start <= b_end && a_end >= b_start))
    {
        cross = a_end - a_start + 1;
        cout << cross;
    }
    else
    {
        cout << 0;
    }
    return 0;
}

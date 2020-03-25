#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int z, z1, safe, count = 0, r = 1;
    cout << "Write down z z1" << endl;
    cin >> z >> z1;
    safe = z + z1;
    if (z > z1)
    {
        swap (z,z1);
    }
    while (r != 0)
    {
        r = safe % z;
        safe = r + z1;
        count ++;

    }
    cout << count*z1;
    return 0;
}

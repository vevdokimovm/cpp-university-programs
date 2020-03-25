#include <iostream>
#include <string>

using namespace std;

string bin_by_mask(unsigned n)
{
    string str = "";
    while (n > 0)
    {
        str = (n & 1 == 1 ? "1" : "0") + str;
        n >>= 1;
    }
    return str;
}

int main()
{
    unsigned n;
    cin >> n;
    cout << bin_by_mask(n) << endl;
    return 0;
}

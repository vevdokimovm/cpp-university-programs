#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    cout << -(n << (31 - k) >> 31)<< endl;
    return 0;
}

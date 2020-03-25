#include <iostream>

using namespace std;

int main()
{
    int sum = 0, nmr;
    cin >> nmr;
    while (nmr != 0)
    {
        sum = sum + nmr;
        cin>>nmr;
    }
    cout << sum << endl;
    return 0;
}

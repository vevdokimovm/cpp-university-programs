#include <iostream>
#define int long long
#include <string>

using namespace std;

main()
{
    long long a = 1000000;
    a = a * a;
    cout << a % (1LL << 32) << endl;
    cout << (a % (1LL << 32) - (1LL << 32)) << endl;
    return 0;
}
/* */

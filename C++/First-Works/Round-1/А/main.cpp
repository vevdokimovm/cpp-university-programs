#include <iostream>

using namespace std;

int main()
{
    unsigned long long n, dec;
    cin >> n;
    dec = n % 10;
    if (dec > 5){
        cout << n + (10 - dec);
    } else {
        cout << n - dec << endl;
    }
    return 0;
}

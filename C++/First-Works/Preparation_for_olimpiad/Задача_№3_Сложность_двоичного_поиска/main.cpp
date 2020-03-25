#include <iostream>

using namespace std;

int main()
{
    long long n, count = 0;
    cin >> n;
    if (n % 2 == 0 && n != 0){
        count = -1;
    }
    while (n >= 1){
        n /= 2;
        count++;
    }
    cout << count << endl;
    return 0;
}

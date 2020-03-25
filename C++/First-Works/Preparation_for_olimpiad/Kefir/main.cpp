#include <iostream>

using namespace std;

int main()
{
    long long int n, a, b, c, count = 0;
    cin >> n >> a >> b >> c;
    if (b <= n){
        b = b - c;
    }
    int m = min(a,b);
    int ans = n / m;
    if (ans - a >= 0){
        cout << ans + 1;
    } else {
        cout << ans;
    }
    /* while (n >= a || n >= b){
        if (b - c <= a && b <= n){
            n -= b + c;
            count++;
        } else {
            n -= a;
            count++;
        }
    }
    cout << count << endl; */
    return 0;
}

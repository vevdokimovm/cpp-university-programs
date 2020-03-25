#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    short n;
    long long s;
    scanf("%hd", &n);
    vector <long long> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    if ((int)a.size() == 2){
        cout << abs(a[1] - a[0]);
        return 0;
    } else if ((int)a.size() == 1){
        cout << 0;
        return 0;
    }
    long long r1 = abs(a[1] - a[0]) + abs(a[2] - a[1]);
    long long r2 = 3 * abs(a[2] - a[0]);
    a[2] = min(r1, r2);
    a[1] = abs(a[1] - a[0]);
    for (int i = 3; i < n; i++){
        long long v1 = 3 * abs(a[i] - a[i + 2]);
        long long v2 = abs(a[i + 1] - a[i + 2]) + abs(a[i] - a[i + 1]);
        if (min(v1, v2) == v1){
             s = a[i - 2];
             i++;
        } else {
             s = a[i - 1];
        }
        a[i] = min(v1, v2) + s;
        a[i - 1] = abs(a[i - 1] - a[i - 2]);
    }
    short last = (int)a.size() - 1;
    cout << a[last];
    return 0;
}

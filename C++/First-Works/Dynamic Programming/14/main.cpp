#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    short n;
    long long ans = 0, s;
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
    for (int i = 0; i < n; i++){
        long long v1 = 3 * abs(a[i] - a[i + 2]);
        long long v2 = abs(a[i] - a[i + 1]) + abs(a[i + 1] - a[i + 2]);
        if (min(v1, v2) == v2){
            s =
        } else {
            i++;
            s =
        }

    return 0;
}

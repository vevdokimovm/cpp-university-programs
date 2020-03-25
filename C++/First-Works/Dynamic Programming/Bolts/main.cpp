#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    //freopen("c:\\users\\home\\desktop\\bolts.txt", "r", stdin);
    //freopen("c:\\users\\home\\desktop\\outputbolts.txt", "w", stdout);
    short n, l = 0;
    cin >> n;
    vector <short> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        short ind = i;
        for (int j = i + 1; j < n; j++){
            if (a[ind] > a[j]){
                ind = j;
            }
        }
        int temp = a[i];
        a[i] = a[ind];
        a[ind] = temp;
    }
    for (int i = 0; i < n - 1; i++){
        l += a[i + 1] - a[i];
    }
    cout << l;
    return 0;
}

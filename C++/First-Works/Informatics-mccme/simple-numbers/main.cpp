#include <bits/stdc++.h>
using namespace std;

void enumerate(int * a, int low, int high){
    for (int i = 0, value = low; i < high - low + 1; ++i, ++value)
        a[i] = value;
}

int next(int divisior){
    if (divisior == 2)
        return 3;
    else
        return divisior + 2;
}

int square(int x) { return x * x; }

bool is_prime(int n, int divisior = 2){
    if (square(divisior) > n)
        return true;
    else if (remainder(n, divisior) == 0)
        return false;
    else
        return is_prime(n, next(divisior));
}

int main()
{
    int low = 0;
    int high = 0;
    cin >> low >> high;
    int len = high - low + 1;
    int a[len] = {};
    enumerate(a, low, high);

    bool exist = 0;
    for (int i = 0; i < len; ++i)
        if (is_prime(a[i])){
            cout << a[i] << endl;
            exist = true;
        }

    if (!exist)
        cout << "Absent";

    return 0;
}

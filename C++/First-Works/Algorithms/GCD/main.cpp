#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b){
    while (a != 0 && b != 0){
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

int main()
{
    int a, b;
    long long l = 1000000000;
    l *= l;
    cin >> a >> b;
    printf("%lld", l);
    //cout << gcd(a, b) << endl;
    return 0;
}

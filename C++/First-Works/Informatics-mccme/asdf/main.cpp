#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

void enumerate(ll interval[], ll low, ll high){
    ll len = high - low + 1;
    for (ll i = 0, value = low; i < len; ++i, ++value)
        interval[i] = value;
}

void filter(ll* interval, ll len){
    for (ll i = 0; i < len; ++i)
        if (interval[i] == 6
         || interval[i] == 28
         || interval[i] == 496
         || interval[i] == 8128
         || interval[i] == 33550336LL
         || interval[i] == 8589869056LL
         || interval[i] == 137438691328LL)
         cout << interval[i] << endl;
}

int main()
{
    ll low = 0;
    ll high = 0;
    cin >> low >> high;
    ll interval[high - low + 1] = {};
    enumerate(interval, low, high);
    filter(interval, high - low + 1);
    return 0;
}

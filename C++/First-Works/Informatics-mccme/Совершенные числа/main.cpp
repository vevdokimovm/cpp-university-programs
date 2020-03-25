#include <iostream>
#include <cmath>

using namespace std;
using ull = unsigned long long;

void enumerate(ull interval[], ull low, ull high){
    ull len = high - low + 1;
    for (size_t i = 0, value = low; i < len; ++i, ++value)
        interval[i] = value;
}

bool is_divisior(ull num, ull divisior){
    return (remainder(num, divisior) == 0);
}


ull sum_divisiors(ull num){
    ull sum = 1;
    ull half = num / 2;
    bool flag = is_divisior(num, 2);
    for (size_t divisior = 2; divisior <= half; (flag || divisior == 2 ? ++divisior : divisior += 2)){
        if (sum > num)
            return 0;
        if (is_divisior(num, divisior))
            sum += divisior;
    }
    return sum;
}

bool is_perfect(ull num){
    if (sum_divisiors(num) == num)
        return true;
    return false;
}

void filter(ull* interval, ull len){
    for (size_t i = 0; i < len; ++i)
        if (interval[i] % 2 == 0)
            if (is_perfect(interval[i]))
                cout << interval[i] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    ull low = 1;
    ull high = 100000;
    //cin >> low >> high;
    ull interval[high - low + 1] = {};
    enumerate(interval, low, high);
    filter(interval, high - low + 1);
    //for (size_t i = 0; i < high - low + 1; ++i)
    //    cout << interval[i] << " ";
    return 0;
}

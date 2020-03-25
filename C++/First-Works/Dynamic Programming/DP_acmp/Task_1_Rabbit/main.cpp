#include <iostream>
#include <string>
#include <algorithm>

#define info(msg) cout << #msg << " = " << msg << endl;

int counter = 0;

using ull = unsigned long long;
using ll = long long;
using std::string;
using std::cin;
using std::cout;
using std::endl;

//Summarize two numbers represented by strings
string long_arithmetic(string const str1, string const str2){
    int remain = 0;
    string new_sum = "";
    int value = 0;
    int max_size = std::max(str1.size(), str2.size()) - 1;
    for (int first = str1.size() - 1, second = str2.size() - 1; max_size >= 0; --first, --second, --max_size){
        if (first <= -1)
            value = str2[second] - '0' + remain;
        else if (second <= -1)
            value = str1[first] - '0' + remain;
        else
            value = (str1[first] - '0') + (str2[second] - '0') + remain;
        if (value < 10){
            new_sum.push_back(value + '0');
            remain = 0;
        }
        else {
            new_sum.push_back((value % 10) + '0');
            remain = 1;
        }
    }
    if (remain == 1)
        new_sum.push_back('1');
    reverse(new_sum.begin(), new_sum.end());
    return new_sum;
}

//DP algorithm
std::string value(std::string a[], short i, short jump){
    std::string sum = a[i - 1];
    for (ll j = i - 2; j >= 0 && j + jump >= i; --j)
        sum = long_arithmetic(sum, a[j]);
    return sum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    short jump = 0;
    short stairs = 0;
    cin >> jump >> stairs;
    string a[stairs + 1] = {"1"};
    for (short i = 1; i < stairs + 1; ++i)
        a[i] = value(a, i, jump);
    cout << a[stairs] << endl;
    return 0;
}

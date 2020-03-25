#include <iostream>
#include <cmath>

using namespace std;

int sms(string a, string b){
    if (a.length() > b.length())
        swap(a, b);
    int add = b.length() - a.length(), a1 = 0, b1 = 0;
    for (int i = 0; i < add; i++)
        a = '0' + a;
    int count = 0, last = b.length() - 1;
    for (unsigned i = last; i >= 0; i--){
        int m = a[i] - '0';
        int m1 = b[i] - '0';
        a1 += m * pow(10, count);
        b1 += m1 * pow(10,count);
        count++;
    }
    int t = a1 - b1;
    return t;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << sms(s1, s2) << endl;
    return 0;
}

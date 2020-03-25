#include <iostream>

using namespace std;

string myp(string a, string b){
    string r = "";
    if (a.length() > b.length())
        swap(a, b);
    int sum = (int)b.length() - (int)a.length() + 1;
    for (int i = 0; i < sum; i++){
        a = '0' + a;}
    b = '0' + b;
    for (int i = (int)b.length() - 1; i >= 0; i--){
        char c = a[i] + b[i] - '0';
        if (c > '9'){
            b[i - 1] += 1;
            char c1 = c - '9' + '0';
            char c2 = (int)c1 - 1;
            r = c2 + r;
        } else {
            r = c + r;
        }
    }
    return r;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    string s3 = myp(s1, s2);
    if (s3[0] == '0'){
        s3.erase(s3.begin());
    }
    cout << s3;
    return 0;
}

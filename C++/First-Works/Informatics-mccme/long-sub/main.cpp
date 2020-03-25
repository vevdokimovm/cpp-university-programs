#include <bits/stdc++.h>
#define info(msg) cout << #msg << " = " << msg << endl;
using namespace std;

void add_zeros(string& str, size_t len){
    size_t dif = len - str.size();
    for (size_t i = 0; i < dif; ++i)
        str = "0" + str;
}

string long_sub(string & n1, string & n2){
    bool flag = (n1.size() > n2.size());
    add_zeros((flag ? n2 : n1), (flag ? n1.size() : n2.size()));
    int last = n1.size() - 1;
    int borrowed = 0;
    int value = 0;
    string result = "";
    for (int i = last; i >= 0; --i){
        value = n1[i] - '0' - (n2[i] - '0') - borrowed;
        if (value < 0)
            result.push_back(value + 10 + '0'), borrowed = 1;
        else
            result.push_back(value + '0'), borrowed = 0;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    string n1 = "";
    string n2 = "";
    cin >> n1 >> n2;
    cout << long_sub(n1, n2);
}

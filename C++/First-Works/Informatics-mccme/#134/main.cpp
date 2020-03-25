#include <bits/stdc++.h>
#define info(msg) cout << #msg << " = " << msg << endl;
using namespace std;

void add_zeros(string& str, size_t len){
    size_t dif = len - str.size();
    for (size_t i = 0; i < dif; ++i)
        str = "0" + str;
}

char compare(string const & n1, string const & n2){
    if (n1.size() > n2.size())
        return '>';
    else if (n1.size() < n2.size())
        return '<';
    else {
        int last = n1.size();
        for (int i = 0; i < last; ++i)
            if (n1[i] > n2[i])
                return '>';
            else if (n1[i] < n2[i])
                return '<';
    }
    return '=';
}

string long_sub(string & n1, string & n2){
    bool flag = (n1.size() > n2.size());
    add_zeros((flag ? n2 : n1), (flag ? n1.size() : n2.size()));
    int last = n1.size() - 1;
    int borrowed = 0;
    int value = 0;
    string result = "";
    bool minus_ = false;
    if (compare(n1, n2) == '=')
        return "0";
    else if (compare(n1, n2) == '<')
        swap(n1, n2), minus_ = true;
    for (int i = last; i >= 0; --i){
        value = n1[i] - '0' - (n2[i] - '0') - borrowed;
        if (value < 0)
            result.push_back(value + 10 + '0'), borrowed = 1;
        else
            result.push_back(value + '0'), borrowed = 0;
    }
    if (minus_)
        result.push_back('-');
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    string n1 = "";
    string n2 = "";
    cin >> n1 >> n2;
    cout << long_sub(n1, n2);
}

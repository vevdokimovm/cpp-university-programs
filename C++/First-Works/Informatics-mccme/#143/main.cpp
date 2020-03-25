#include <bits/stdc++.h>

#define info(msg) cout << #msg << " = " << msg << endl;
using namespace std;

void add_zeros(string& str, int len){
    for (int i = 0; i < len; ++i)
        str = '0' + str;
}

string add_long(string& str1, string str2){
    bool flag = (str1.size() > str2.size());
    add_zeros((flag ? str2 : str1), (flag ? str1.size() - str2.size() : str2.size() - str1.size()));
    int remain = 0;
    int value = 0;
    string result = "";
    int last = str1.size() - 1;
    for (int i = last; i >= 0; --i){
        value = str1[i] - '0' + str2[i] - '0' + remain;
        if (value < 10)
            result.push_back(value + '0'), remain = 0;
        else
            result.push_back(value % 10 + '0'), remain = 1;
    }
    if (remain == 1)
        result.push_back('1');
    reverse(result.begin(), result.end());
    return result;
}

string long_product(string str1, string str2){
    cout << "Start processing" << endl;
    int remain = 0;
    int value = 0;
    int last_s1 = str1.size() - 1;
    int last_s2 = str2.size() - 1;
    string result = "";
    for (int second = last_s2, discharge = 0; second >= 0; --second, ++discharge){
        string temp_result = "";
        add_zeros(temp_result, discharge);
        for (int first = last_s1; first >= 0; --first){
            value = (str1[first] - '0') * (str2[second] - '0') + remain;
            if (value < 10)
                temp_result.push_back(value + '0'), remain = 0;
            else
                temp_result.push_back(value % 10 + '0'), remain = value / 10;
        }
        if (remain)
            temp_result.push_back(remain + '0'), remain = 0;
        reverse(temp_result.begin(), temp_result.end());
        result = add_long(result, temp_result);
    }
    cout << "End processing" << endl;
    return result;
}

string one = "1";

string minus_one(string str){
    int borrowed = 1;
    int last = str.size() - 1;
    int value = 0;
    for (int i = last; i >= 0; --i){
        value = str[i] - '0' - borrowed;
        if (value < 0){
             str[i] = value + 10 + '0';
        } else if (value == 0 && i == 0 && str != one){
            str.erase(i, 1);
            return str;
        } else {
            str[i] = value + '0';
            return str;
        }
    }
    return str;
}

string factorial(string str){
    int n = stoi(str);
    info(n);
    if (n == 0)
        return one;
    else
        return long_product(str, (factorial(minus_one(str))));
}

int main(){
    string fact = "";
    cin >> fact;
    cout << factorial(fact);
    //cout << minus_one(fact);
}

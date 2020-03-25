#include <iostream>
#include <algorithm>
#define info(msg) cout << #msg << " = " << msg << endl;
using namespace std;

void add_zeros(string& str1, size_t len){
    size_t dif = len - str1.size();
	for (size_t i = 0; i < dif; ++i)
		str1 = "0" + str1;
}

string long_sum(string & n1, string n2){
	add_zeros((n1.size() > n2.size() ? n2 : n1)
            , (n1.size() > n2.size() ? n1.size() : n2.size()));
	size_t last = n1.size() - 1;
	int value = 0;
	int remain = 0;
	string result = "";
	for (int i = last; i >= 0; --i){
        value = n2[i] - '0' + n1[i] - '0' + remain;
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

int main(){
	string n1 = "";
	cin >> n1;
	cout << long_sum(n1, "1");
}

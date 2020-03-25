#include <iostream>

using namespace std;

void add_zeros(string& str1, size_t len){
	for (size_t i = 0; i < len - str1.size(); ++i)
		str1 = "0" + str1;
}

void long_sum(string n1, string n2){
	add_zeros((n1.size() > n2.size() ? n2 : n1), (n1.size() > n2.size() ? n1.size() : n2.size()));
	return;
}

int main(){
	string n1 = "";
	string n2 = "";
	cin >> n1 >> n2;
	long_sum(n1, n2);
}
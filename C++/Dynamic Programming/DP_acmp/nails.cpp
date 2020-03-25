#include <iostream>

using std::cout;
using std::endl;
using ull = unsigned long long;

int main(){
	short n = 0;
	cin >> n;
	ull a[n] = {};
	for (size_t i = 0; i < n; ++i)
		cin >> a[i];
	ull l = 0;
	for (size_t i = 1; i < n - 1; ++i)
		l += std::min(a[i] - a[i - 1], a[i + 1] - a[i]);
	cout << l;
}
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using ull = unsigned long long;

int main(){
    std::ios::sync_with_stdio(false);
	short n = 0;
	cin >> n;

	//Init
	ull a[n + 1] = {};
	for (size_t i = 0; i < n; ++i)
		cin >> a[i];


	std::sort(a, a + n);
	ull l = a[1] - a[0];

	//DP
	for (size_t i = 2; i < n; ++i){
        ull left = a[i] - a[i - 1];
        ull right = a[i + 1] - a[i];
        ull opt = std::min(left, right);
        l += opt;
        if (opt == right)
            ++i;
	}
	cout << l << endl;
}

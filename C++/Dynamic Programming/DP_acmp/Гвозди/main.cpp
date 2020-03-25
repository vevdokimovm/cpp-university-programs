#include <iostream>

using namespace std;

int main(){
	size_t stairs = 0;
	cin >> stairs;
	size_t a[stairs + 3] = {0, 0, 1};
	for (size_t i = 3; i < stairs + 3; ++i)
		a[i] = a[i - 1] + a[i - 2] + a[i - 3];
	cout << a[stairs + 2];
}

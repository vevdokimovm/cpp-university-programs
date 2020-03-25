#include <iostream>
#include <cmath>
using namespace std;


void fibonaci_Bine(short n){
	long double sqrt5 = sqrt(5);
	long double phi = (1 + sqrt5) / 2;
	long double psi = (1 - sqrt5) / 2;
	int nth = (pow(phi, n) - pow(psi, n)) / sqrt5;
	cout << nth;
}

int main(){
	short n = 0;
	cin >> n;
	fibonaci_Bine(n);
}
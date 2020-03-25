#include <iostream>
#include <cmath>

using namespace std;

int CountPrime(int a, int d, int c){
    if (a == 0){
        return c;
    } else if (a == 1){
        return c + 1;
    } else if (a % d != 0){
        c++;
        return c + CountPrime(a - 1, d + 1, c);
    }
}

int main(){
    int n, div = 2, count = 0;
    cin >> n;
    cout << CountPrime(n, div, count);

}

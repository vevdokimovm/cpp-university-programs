#include <iostream>
#include <cmath>

using namespace std;

int bit_zero(unsigned a, unsigned b){
    unsigned temp = a, rt = 0;
    for (unsigned short i = 0; i < 32; i++){
        if (i == b){
            if ((a & 1) == 1){
                rt = 2;
            } else {
                break;
            }
            b == 0 ? rt = pow(rt, 0) : rt = pow(rt, b);
            break;
        } else {
            a >>= 1;
        }
    }
    temp -= rt;
    return temp;
}

int main()
{
    unsigned n, k;
    cin >> n >> k;
    cout << bit_zero(n, k);
    return 0;
}

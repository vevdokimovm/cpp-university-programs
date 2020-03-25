#include <iostream>

using namespace std;

double Power(double a, int b){
    if (b == 0){
        return 1;
    }
     if (b % 2 == 0){
        a = a * a;
        b = b / 2;
    }
    return a * Power(a, b - 1);
}

int main()
{
    int n;
    double a;
    cin >> a >> n;
    cout << Power(a, n) << endl;
    return 0;
}

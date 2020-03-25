#include <iostream>

using namespace std;

int fib_iter(int a, int b, int count){
    if (count == 0){
        return b;
    }
    return fib_iter(a + b, a, count - 1);
}


int Fib(int n){
    return fib_iter(1, 0, n);
}

int main()
{
    int a;
    cin >> a;
    cout << Fib(a) << endl;
    return 0;
}

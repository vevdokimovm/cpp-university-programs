#include <iostream>

using namespace std;

int smth(int a, int b, int c){
    return a + b + c;
}

int main()
{
    cout << smth(c=4, b = 3, a = 2);
    return 0;
}

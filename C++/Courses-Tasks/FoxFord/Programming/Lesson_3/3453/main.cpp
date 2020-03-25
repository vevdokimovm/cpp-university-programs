#include <iostream>

using namespace std;

int main()
{
    short a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a >= 0 && c >= 0){
    cout << max(a, c) << endl;
    } else if (a >= 0 && c <= 0){
        cout << a + (- c);
    } else if (a <= 0 && c >= 0){
        cout << (- a) + c;
    } else {
        cout << -min(a, c);
    }
    return 0;
}

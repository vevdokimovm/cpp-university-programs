#include <iostream>
#include <string>

using namespace std;

int main()
{
    short n, k;
    string s = "";
    cin >> n >> k;
    while (k > 0){
        s = (n & 1 == 1 ? "1" : "0") + s;
        n >>= 1;
        k--;
    }
    cout << s;
    return 0;
}

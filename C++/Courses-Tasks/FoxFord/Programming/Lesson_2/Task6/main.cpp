#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string s;
    short k = 0, ans = 0;
    cin >> s;
    for (short i = (short)s.size() - 1; i >= 0; i--){
        if (s[0] == '1'){
            if (s[i] == '0'){
                ans += - (1 << k);
                k++;
            } else {
                k++;
            }
        } else {
            if (s[i] == '1'){
                ans += 1 << k;
                k++;
            } else {
                k++;
            }
        }
    }
    cout << (ans >= 0 ? ans : ans - 1) << endl;
    return 0;
}

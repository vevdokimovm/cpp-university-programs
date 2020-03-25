#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    short int a, ans = 0, count = 0;
    cin >> a;
    for (int i = 1; i < a; i++){
        count = 0;
        short int i_sqrt = sqrt(i);
        for (int j = 3; j <= i_sqrt; j++){
            if (i % j == 0){
                count = 0;
                break;
            } else {
                count++;
            }
        }
        if (count > 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}

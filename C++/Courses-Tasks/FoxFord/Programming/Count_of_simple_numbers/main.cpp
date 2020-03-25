#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned long long ans = 0, count = 0;
    for (unsigned long long i = 4; i <= 11; i++){
        count = 0;
        unsigned long long i_sqrt = trunc(sqrt(i)) + 1;
        for (unsigned long long j = 3; j <= i_sqrt; j++){
            if (i % j == 0){
                count = 0;
                break;
            } else {
                count++;
            }
        }
        if (count != 0)
            ans++;
    }
    cout << ans - 2<< endl;
    return 0;
}

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int x, y, all_rub, cost_cola, cost_bars, res = 0;
    cin >> all_rub >> cost_cola >> cost_bars;
    for (int i = 0; i <= all_rub; i++){
        for (int j = 0; j <= all_rub; j++){
            res = i * cost_cola + j * cost_bars;
            if (res == all_rub){
                x = i;
                y = j;
                cout << "YES\n" << x << " " << y;
                exit(0);
            } else if (res > all_rub){
                break;
            }
        }
    }
    cout << "NO";
    return 0;
}

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    short n = 0, counter = 0, dif = 0;
    cin >> n;
    short diag[n][n] = {};
    short iters = 2 * n - 1;
    for (short i = 0; i < iters; ++i){
        for (short s = (i >= n ? ++dif : 0), c = (i >= n ? (n - 1) : i); c >= 0 && s < n; --c, ++s){
            diag[s][c] = ++counter;
        }
    }
    for (short i = 0; i < n; ++i){
        for (short j = 0; j < n; ++j)
            cout << setw(6) << diag[i][j] << " ";
        cout << endl;
    }
    return 0;
}

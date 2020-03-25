#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    short rows = 0, cols = 0, counter = 0, dif = 0;
    cin >> rows >> cols;
    short diag[rows][cols] = {};
    short iters = rows + cols - 1;
    for (short i = 0; i < iters; ++i){
        for (short s = (i >= cols ? ++dif : 0), c = (i >= cols ? (cols - 1) : i); c >= 0 && s < rows; --c, ++s){
            diag[s][c] = ++counter;
        }
    }
    for (short i = 0; i < rows; ++i){
        for (short j = 0; j < cols; ++j)
            cout << setw(3) << diag[i][j] << " ";
        cout << endl;
    }
    return 0;
}

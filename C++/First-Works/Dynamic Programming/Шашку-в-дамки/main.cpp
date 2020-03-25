#include <iostream>

using namespace std;

int sum(int a[]){
    int sum_ = 0;
    for (int i = 1; i < 9; ++i)
        sum_ += a[i];
    return sum_;
}

int main()
{
    int row = 0;
    int col = 0;
    cin >> col >> row;
    int a[10][10] = {};
    a[9 - row][col] = 1;
    for (int i = 8; i > 0; --i)
        for (int j = 1; j < 9; ++j)
            a[i][j] += a[i + 1][j - 1] + a[i + 1][j + 1];
    cout << sum(a[1]);
    return 0;
}

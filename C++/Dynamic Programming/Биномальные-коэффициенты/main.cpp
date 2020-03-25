#include <iostream>

using namespace std;
using ull = unsigned long long;
int main()
{
    unsigned rows = 0;
    unsigned cols = 0;
    cin >> rows >> cols;
    ull** a = new ull*[rows + 1];
    a[0] = new ull[(rows + 1) * (cols + 1)];
    for (size_t i = 1; i < rows + 1; ++i)
        a[i] = a[i - 1] + cols + 1;
    for (size_t i = 0; i < rows + 1; ++i)
        for (size_t j = 0; j < cols + 1; ++j)
            a[i][j] = 0;
    a[1][0] = 1;
    for (size_t i = 1; i < rows + 1; ++i)
        for (size_t j = 1; j < cols + 1; ++j)
            a[i][j] = a[i - 1][j] + a[i][j - 1];
    cout << a[rows][cols];
    return 0;
}

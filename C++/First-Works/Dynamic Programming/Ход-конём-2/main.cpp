#include <iostream>
#define FOR() \
for (size_t i = 2; i < rows + 2; ++i) \
    for (size_t j = 2; j < cols + 2; ++j)


using namespace std;
using u = unsigned;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    u rows = 0;
    u cols = 0;
    cin >> rows >> cols;

    u a[rows + 3][cols + 3] = {};
    a[0][1] = 1;
    FOR() a[i][j] = a[i - 2][j + 1]
                  + a[i - 2][j - 1]
                  + a[i - 1][j - 2]
                  + a[i + 1][j - 2];

    cout << a[rows + 1][cols + 1] << endl;


    return 0;
}

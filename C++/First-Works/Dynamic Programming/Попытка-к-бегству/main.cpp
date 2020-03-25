#include <iostream>
#define FOR() \
for (size_t i = 1; i < rows + 1; ++i) \
    for (size_t j = 1; j < cols + 1; ++j)


using namespace std;

int main()
{
    using ull = unsigned long long;
    unsigned rows = 0;
    unsigned cols = 0;
    cin >> rows >> cols;
    unsigned prison[rows + 2][cols + 2] = {};
    FOR() cin >> prison[i][j];

    ull dp[rows + 2][cols + 2] = {};
    dp[0][1] = 1;
    FOR(){
        if (prison[i][j] == 1) dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
    }
    if (dp[rows][cols] == 0)
        cout << "Impossible";
    else
        cout << dp[rows][cols];

    return 0;
}

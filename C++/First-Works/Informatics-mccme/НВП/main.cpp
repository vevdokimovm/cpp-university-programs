#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int index_greatest(int dp[], int len){
    int ans = 0, pos = 0;
    for (int i = 0; i < len; ++i)
        if (ans < dp[i]){
            ans = dp[i];
            pos = i;
        }
    cout << ans << endl;
    return pos;
}

void print(vector<int> path){
    reverse(path.begin(), path.end());

    for (size_t i = 0; i < path.size(); ++i)
        cout << path[i] << " ";
}

int main()
{
    int n = 0;
    cin >> n;

    int a[n] = {};
    int dp[n] = {1};
    int p[n] = {};
    for (int i = 0; i < n; ++i) cin >> a[i];

    //DP
    for (int i = 0; i < n; ++i){
        dp[i] = 1;
        p[i] = -1;
        for (int j = 0; j <= i - 1; ++j)
            if (a[j] < a[i])
                if (dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    p[i] = j;
                }
    }

    vector <int> path;
    int pos = index_greatest(dp, n);
    while (pos != -1){
        path.push_back(a[pos]);
        pos = p[pos];
    }
    print(path);
    return 0;
}

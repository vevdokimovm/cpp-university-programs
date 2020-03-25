#include <iostream>
#include <cstdlib>

    using u = unsigned;
    using namespace std;
int greatest(int dp[], int n){
    int ans = dp[0];
    for (int i = 0; i < n; ++i)
        ans = max(ans, dp[i]);
    return ans;
}

int main(){
    int n = 0;
    scanf("%u", &n);
    //cin >> n;
    int a[n] = {};
    int dp[n] = {1};


    for (int i = 0; i < n; ++i)
        scanf("%u", &a[i]);
        //cin >> a[i];

    for (int i = 1; i < n; ++i){
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
    }

    //cout << greatest(dp, n);
    printf("%u", greatest(dp, n));
}

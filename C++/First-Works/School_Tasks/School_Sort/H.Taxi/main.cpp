#include <iostream>
#include <vector>
#include<algorithm>
#include <utility>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.first >= b.first;
}

/* bool comp1(pair<int, int> a, pair<int, int> b){
    if (a.first )
    return
}
*/

int main()
{
    int n;
    cin >> n;
    vector <pair <int, int>> km(n);
    vector <pair <int, int>> cost(n);
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        km[i] = {temp, i + 1};
    }
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        cost[i] = {temp, i + 1};
    }
    sort(km.begin(), km.end(), comp);
    sort(cost.begin(), cost.end());
    reverse(cost.begin(), cost.end());
    for (auto now : cost){
        cout << now.second << " ";
    }
    return 0;
}

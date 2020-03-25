#include <iostream>
#include <vector>
#include<utility>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;
    vector <pair <int, int>> co(n);
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        co[i] = {x, y};
    }
    sort(co.begin(), co.end());
    reverse(co.begin(), co.end());
    /*for (auto now : co){
        cout << now.first << " " << now.second << "\n";
    } */
    while (co.size() > 0){
        for (unsigned i = 0; i < co.size(); i++){
            for (unsigned j = i + 1; j < co.size(); j++){
                if (co[i].first == co[j].first){
                    co.erase(co.begin() + j);
                    j--;
                }
            }
            co.erase(co.begin() + i);
            count++;
        }
    }
    cout << count ;
    return 0;
}

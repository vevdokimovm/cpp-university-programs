#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp(pair <long long unsigned, long long unsigned> a, pair <long long unsigned, long long unsigned> b){
    return a.first < b.first;
}

int main ()
{
    long long unsigned n = 0, m = 0;
    cin >> n;
    vector <pair <long long unsigned, long long unsigned>> n1(n);
    for (size_t i = 0; i < n; ++i){
        long long unsigned element = 0, cost = 0;
        cin >> element >> cost;
        n1[i].first = element;
        n1[i].second = cost;
    }
    cin >> m;
    vector <pair <long long unsigned, long long unsigned>> m1(m);
    for (size_t i = 0; i < m; ++i){
        long long unsigned element = 0, cost = 0;
        cin >> element >> cost;
        m1[i].first = element;
        m1[i].second = cost;
    }
    sort(n1.begin(), n1.end(), cmp);
    sort(m1.begin(), m1.end(), cmp);
    long long unsigned sum = 0;
    bool flag = 0;
    for (size_t i = 0; i < n; ++i){
        for (size_t j = 0; j < m && (n1[i].first >= m1[j].first); ++j){
            if (n1[i].first == m1[j].first){
                sum += max(n1[i].second, m1[i].second);
                flag = 1;
                break;
            }
        }
        if (!flag){
            sum += n1[i].second;
        }
        flag = 0;
    }
    for (size_t i = 0; i < m; ++i){
        for (size_t j = 0; j < n && (m1[i].first >= n1[j].first); ++j){
            if (m1[i].first == n1[j].first){
                flag = 1;
                break;
            }
        }
        if (!flag){
            sum += m1[i].second;
        }
        flag = 0;
    }
    cout << sum;
}

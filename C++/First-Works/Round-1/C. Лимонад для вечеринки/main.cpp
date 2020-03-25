#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    long long n, l, index;
    cin >> n >> l;
    vector <long long> cost(n);
    vector <long long> v(n);
    vector <long long> ans(n);
    vector <long long> count_litrov(n);
    for (long long i = 0; i < n; i++){
        cin >> cost[i];
    }
    for (long long i = 0; i < n; i++){
        v[i] = pow(2, i);
    }
    long long min2 = cost[0];
    //Поиск минимальной стоимости
    for (long long j = 0; j < n; j++){
        for (long long i = i + 1; i < n; i++){
            if (min2 > cost[i]){
                min2 = cost[i];
                index = i;
                swap(cost[j], cost[i]);
            }
        }
    //Кол - во денег для покупки этого объёма
        while (count_litrov[j] < l){
            ans[j] += min2;
            count_litrov[j] += v[index];
        }
    }
    long long min1 = ans[0];
    for (long long i = 1; i < n; i++){
        if (min1 > ans[i]){
            min1 = ans[i];
        }
    }
    cout << min1;
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <climits>
using namespace std;

bool cmp(pair<unsigned, unsigned> b, pair<unsigned, unsigned> c){
    return b.second < c.second;
}

int main()
{
    unsigned short min_score = 0, task_count = 0;
    cin >> min_score >> task_count;
    vector <pair <unsigned, unsigned>> a(task_count);
    for (size_t i = 0; i < task_count; ++i){
        unsigned score = 0, hours = 0;
        cin >> score >> hours;
        a[i].first = score;
        a[i].second = hours;
    }
    sort(a.begin(), a.end(), cmp);
    unsigned hours[task_count] = {};
    for (size_t i = 0; i < task_count; ++i){
        unsigned score = 0, min_hours = 0;
        for (size_t j = i; j < task_count && score < min_score; ++j){
            min_hours += a[j].second;
            score += a[j].first;
        }
        if (score >= min_score)
            hours[i] = min_hours;
        else
            hours[i] = UINT_MAX;
    }
    unsigned * overall_hours_min = min_element(hours, hours + task_count);
    cout <<  * overall_hours_min;
}

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>

using namespace std;

bool cmp1(pair<unsigned, unsigned> a, pair<unsigned, unsigned> b){
    return b.first > a.first;
}
bool cmp2(pair<unsigned, unsigned> a, pair<unsigned, unsigned> b){
    return a.first == b.first && b.second < a.second;
}

int main()
{
    unsigned short score_to_get = 0, task_count = 0;
    cin >> score_to_get >> task_count;
    vector <pair <unsigned, unsigned>> arr(task_count);
    for (size_t i = 0; i < task_count; ++i)
    {
        unsigned ball_i = 0, time_i = 0;
        cin >> ball_i >> time_i;
        arr[i].first = ball_i;
        arr[i].second = time_i;
    }
    sort(arr.begin(), arr.end(), cmp1);
    sort(arr.begin(), arr.end(), cmp2);

    unsigned min_score_task = arr[0].first;
    unsigned max_score_task = arr[task_count - 1].first;

    unsigned cols = 1;
    if (max_score_task < score_to_get)
        cols = score_to_get + 1;
    else
        cols = max_score_task + 1;
    unsigned rows = task_count + 1;
    unsigned ans[rows][cols] = {};


    for (size_t j = 1; j < cols; ++j)
        ans[0][j] = UINT_MAX;

    for (size_t j = 1; j < cols; ++j){
        if (j == min_score_task)
            ans[1][j] = arr[0].second;
        else if (j < min_score_task)
            ans[1][j] = 0;
        else
            ans[1][j] = UINT_MAX;
    }

    unsigned current_sum_of_score = arr[0].first + arr[1].first;
    for (size_t i = 2; i < rows; ++i){
        pair <unsigned, unsigned> task = arr[i - 1];
        for (size_t j = 1; j < cols; ++j){
            if (j < task.first)
                ans[i][j] = ans[i - 1][j];
            else if (j <= current_sum_of_score){
                unsigned remain_score = j - task.first;
                unsigned time_diff = (remain_score > 0 ? task.second + ans[i - 1][remain_score] : task.second);
                ans[i][j] = min(ans[i - 1][j], time_diff);
            } else
                ans[i][j] = UINT_MAX;
        }
        current_sum_of_score += arr[i].first;
    }
    cout << ans[rows - 1][cols - 1] << endl;
    //

    for (size_t i = 0; i < task_count; ++i)
       cout << arr[i].first << " " << arr[i].second << endl;
    for (size_t i = 0; i < rows; ++i){
        for (size_t j = 0; j < cols; ++j)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}

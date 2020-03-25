#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool cmp1(pair<unsigned, unsigned> a, pair<unsigned, unsigned> b){
    return b.first > a.first;
}
bool cmp2(pair<unsigned, unsigned> a, pair<unsigned, unsigned> b){
    return a.first == b.first && b.second < a.second;
}

int main()
{
    unsigned short min_balls = 0, task_count = 0;
    cin >> min_balls >> task_count;
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
    unsigned min_ball = arr[0].first;
    unsigned rows = task_count + 1;
    unsigned cols = min_balls + 1;
    unsigned ans[rows][cols] = {};
        for (size_t j = 1; j < cols; ++j)
            ans[0][j] = UINT_MAX;
    unsigned index = 1;
    unsigned current_sum_of_balls = arr[0].first + arr[1].first;
    for (size_t j = 1; j < cols; ++j){
        if (j == min_ball || ((j == cols - 1) && min_ball > min_balls))
            ans[1][j] = arr[0].second;
        else if (j < min_ball)
            ans[1][j] = 0;
        else
            ans[1][j] = UINT_MAX;
    }
    for (size_t i = 2; i < rows; ++i){
        unsigned current_ball = arr[index].first;
        for (size_t j = 1; j < cols; ++j){
            if (index == 1){
                if ((j == cols - 1) && current_ball > min_balls)
                    ans[i][j] = min(ans[i - 1][j], arr[index].second);
                else if (j == (cols - 1) && current_sum_of_balls >= (j + 1)){
                    if (current_ball >= min_balls)
                        ans[i][j] = min(arr[index].second, ans[i - 1][j]);
                    else {
                        unsigned balls_left = j - current_ball;
                        unsigned * start = ans[i - 1] + max(balls_left, arr[0].first);
                        unsigned * addition = min_element(start, (ans[i - 1] + j));
                        ans[i][j] = min(arr[index].second + *addition, ans[i - 1][j]);
                    }
                }
                else if (j < current_ball)
                    ans[i][j] = ans[i - 1][j];
                else
                {
                    if (j <= current_ball + arr[0].first)
                    {
                        if (current_ball + arr[0].first == j)
                            ans[i][j] = arr[1].second + arr[0].second;
                        else
                        {
                            int remaining_balls = j - current_ball;
                            remaining_balls < 0 ? remaining_balls = 0 : remaining_balls;
                            unsigned remain_slot = arr[index].second + ans[i - 1][remaining_balls];
                            ans[i][j] = min(ans[i - 1][j], remain_slot);
                        }
                    } else
                        ans[i][j] = UINT_MAX;
                }
            }
            else if ((j == cols - 1) && arr[index].first > min_balls)
                ans[i][j] = min(arr[index].second, ans[i - 1][j]);
            else if (j == (cols - 1) && current_sum_of_balls >= (j + 1)){
                    if (current_ball >= min_balls)
                        ans[i][j] = min(arr[index].second, ans[i - 1][j]);
                    else {
                        unsigned balls_left = j - current_ball;
                        unsigned * start = ans[i - 1] + max(balls_left, arr[0].first);
                        unsigned * addition = min_element(start, (ans[i - 1] + j));
                        ans[i][j] = min(arr[index].second + *addition, ans[i - 1][j]);
                    }
                }
            else if (j > current_sum_of_balls)
                ans[i][j] = UINT_MAX;
            else if (j < current_ball)
                ans[i][j] = ans[i - 1][j];
            else {
                int remaining_balls = j - current_ball;
                remaining_balls < 0 ? remaining_balls = 0 : remaining_balls;
                unsigned remain_slot = arr[index].second + ans[i - 1][remaining_balls];
                ans[i][j] = min(ans[i - 1][j], remain_slot);
            }
        }
        current_sum_of_balls += arr[index + 1].first;
        ++index;
    }
    cout << ans[rows - 1][cols - 1];
    return 0;
}

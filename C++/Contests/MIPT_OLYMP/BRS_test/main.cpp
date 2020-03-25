#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

#define DEBUG

#ifdef DEBUG
    #define info(msg, value) cout << msg " = "<< value << endl;
#endif // DEBUG

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
    unsigned max_ball = arr[task_count - 1].first;
    unsigned rows = task_count + 1;
    unsigned cols = 1;
    if (max_ball < min_balls)
        cols = min_balls + 1;
    else
        cols = max_ball + 1;
    unsigned ans[rows][cols] = {};
        for (size_t j = 1; j < cols; ++j)
            ans[0][j] = UINT_MAX;
    unsigned index = 1;
    unsigned current_sum_of_balls = arr[0].first + arr[1].first;
    //Заполняем первую действующую строку массива временем первого элемента
    for (size_t j = 1; j < cols; ++j){
        if (j == min_ball)
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
                if (j < current_ball)
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
        info("current_time", arr[index].second);
        ++index;
        info("index", index);
    }
    cout << ans[rows - 1][cols - 1] << endl;
    info("min_ball", min_ball); info("max_ball", max_ball)
    for (size_t i = 0; i < task_count; ++i)
        cout << arr[i].first << " " << arr[i].second << endl;
    for (size_t i = 1; i < rows; ++i){
       for (size_t j = 1; j < cols; ++ j){
            cout << setw(3) << ans[i][j] << " ";}
        cout << endl;}
    return 0;
}

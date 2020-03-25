#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define info(msg, value) cout << msg " = " << value << endl;
using namespace std;

struct Task
{
    unsigned score;
    unsigned time;
};

bool cmp1(Task a, Task b){
    return b.score > a.score;
}

bool cmp2(Task a, Task b){
    return a.score == b.score && b.time < a.time;
}

int main()
{
    unsigned score_to_get = 0, task_count = 0;
    cin >> score_to_get >> task_count;
    vector <Task> table_input(task_count);
    for (size_t i = 0; i < task_count; ++i)
        cin >> table_input[i].score >> table_input[i].time;
    sort(table_input.begin(), table_input.end(), cmp1);
    sort(table_input.begin(), table_input.end(), cmp2);

    unsigned rows = task_count;
    unsigned cols = score_to_get;


    unsigned dynamic_table[rows][cols] = {};
    for (size_t j = 0; j < cols; ++j){
        if ((j + 1) == table_input[0].score || ((j == cols - 1) && table_input[0].score > score_to_get))
            dynamic_table[0][j] = table_input[0].time;
        else if ((j + 1) < table_input[0].score)
            dynamic_table[0][j] = 0;
        else
            dynamic_table[0][j] = UINT_MAX;
    }


    if (rows >= 2){
        unsigned current_sum_of_score = table_input[0].score + table_input[1].score;
        for (size_t i = 1; i < rows; ++i){
            Task current_task = table_input[i];
            for (size_t j = 0; j < cols; ++j){
                if (j == (cols - 1) && current_sum_of_score >= (j + 1)){
                    if (current_task.score >= score_to_get)
                        dynamic_table[i][j] = min(current_task.time, dynamic_table[i - 1][j]);
                    else {
                        unsigned balls_left = (j + 1) - current_task.score;
                        unsigned * start = dynamic_table[i - 1] + max(balls_left, table_input[0].score);
                        unsigned * addition = min_element(start, (dynamic_table[i - 1] + j));
                        dynamic_table[i][j] = min(current_task.time + *addition, dynamic_table[i - 1][j]);
                        info("balls_left", balls_left);
                        info("max(balls_left, table_input[0].score - 1)", max(balls_left, table_input[0].score));
                        info("*addition", *addition);
                    }
                }
                else if ((j + 1) < current_task.score)
                    dynamic_table[i][j] = dynamic_table[i - 1][j];
                else if ((j + 1) <= current_sum_of_score){
                    unsigned remain_score = (j + 1) - current_task.score;
                    unsigned time_dif = (remain_score > 0 ? (current_task.time + dynamic_table[i - 1][remain_score - 1]) : current_task.time);
                    dynamic_table[i][j] = min(dynamic_table[i - 1][j], time_dif);
                } else
                    dynamic_table[i][j] = UINT_MAX;
            }
            if (i < rows - 1)
                current_sum_of_score += table_input[i + 1].score;
        }
    }
    cout << dynamic_table[rows - 1][cols - 1] << endl;

    for (size_t i = 0; i < task_count; ++i)
       cout << table_input[i].score << " " << table_input[i].time << endl;
    for (size_t i = 0; i < rows; ++i){
        for (size_t j = 0; j < cols; ++j)
            cout << dynamic_table[i][j] << " ";
        cout << endl;
    }
}

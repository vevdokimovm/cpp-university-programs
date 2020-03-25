#include <iostream>
#include <vector>
#include <algorithm>
#define infinity 4294967295

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
    std::ios::sync_with_stdio(false);
    unsigned score_to_get = 0, task_count = 0;
    std::cin >> score_to_get >> task_count;
    std::vector <Task> input_data(task_count);
    for (size_t i = 0; i < task_count; ++i)
        std::cin >> input_data[i].score >> input_data[i].time;
    sort(input_data.begin(), input_data.end(), cmp1);
    sort(input_data.begin(), input_data.end(), cmp2);

    unsigned rows = task_count;
    unsigned cols = score_to_get;


    unsigned dynamic_table[rows][cols] = {};
    for (size_t j = 0; j < cols; ++j)
        if ((j + 1) == input_data[0].score || ((j == cols - 1) && input_data[0].score > score_to_get))
            dynamic_table[0][j] = input_data[0].time;
        else if ((j + 1) < input_data[0].score)
            dynamic_table[0][j] = 0;
        else
            dynamic_table[0][j] = infinity;


    if (rows >= 2){
        unsigned current_sum_of_score = input_data[0].score + input_data[1].score;
        for (size_t i = 1; i < rows; ++i){
            Task current_task = input_data[i];
            for (size_t j = 0; j < cols; ++j){
                // В последнем столбце извлекаем максимальную выгоду, т.к. нужно баллов >= score_to_get
                if (j == (cols - 1) && current_sum_of_score >= score_to_get){
                    if (current_task.score >= score_to_get)
                        dynamic_table[i][j] = std::min(current_task.time, dynamic_table[i - 1][j]);
                    else {
                        unsigned remain_score = (j + 1) - current_task.score;
                        unsigned * begin_search = dynamic_table[i - 1] + std::max(remain_score, input_data[0].score) - 1;
                        unsigned * end_search = dynamic_table[i - 1] + j;
                        unsigned * addition = std::min_element(begin_search, end_search);
                        dynamic_table[i][j] = std::min(current_task.time + *addition, dynamic_table[i - 1][j]);
                    }
                }
                // Не можем ничего поменять
                else if ((j + 1) < current_task.score)
                    dynamic_table[i][j] = dynamic_table[i - 1][j];
                else if ((j + 1) <= current_sum_of_score){
                    unsigned remain_score = (j + 1) - current_task.score;
                    unsigned time_dif = (remain_score > 0 ? (current_task.time + dynamic_table[i - 1][remain_score - 1]) : current_task.time);
                    time_dif = (dynamic_table[i - 1][remain_score - 1] == infinity && remain_score > 0 ? infinity : time_dif);
                    dynamic_table[i][j] = std::min(dynamic_table[i - 1][j], time_dif);
                } else
                    dynamic_table[i][j] = infinity;
            }
            if (i < rows - 1)
                current_sum_of_score += input_data[i + 1].score;
        }
    }
    std::cout << dynamic_table[rows - 1][cols - 1];
}

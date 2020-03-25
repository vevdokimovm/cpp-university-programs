#include <iostream>
#include <queue>
#define WALL -1
#define FREE -2
struct Point
{
    int row;
    int col;
};

int BFS(int * field, Point start, Point finish, int rows, int cols)
{
    int sides_col[] = {1, 0, -1, 0};
    int sides_row[] = {0, 1, 0, -1};
    std::queue <Point> qu;
    qu.push(start);
    bool used[rows * cols] = {};
    used[start.row * cols + start.col] = true;
    while (!qu.empty() && used[finish.row * cols + finish.col] == false){
        Point cur_point = qu.front();
        qu.pop();
        for (int i = 0; i < 4; ++i){
            int neigh_row = cur_point.row + sides_row[i];
            int neigh_col = cur_point.col + sides_col[i];
            if (neigh_row >= 0 && neigh_row < rows && neigh_col >= 0 && neigh_col < cols && field[neigh_row * cols + neigh_col] == FREE && !used[neigh_row * cols + neigh_col]){
                used[neigh_row * cols + neigh_col] = true;
                field[neigh_row * cols + neigh_col] = field[cur_point.row * cols + cur_point.col] + 1;
                Point point1 = {neigh_row, neigh_col};
                qu.push(point1);
            }
        }
    }
    return field[finish.row * cols + finish.col];
}

int main()
{
    std::ios::sync_with_stdio(false);
    int cols = 0, rows = 0;
    std::cin >> cols >> rows;
    int field[rows * cols] = {};
    Point start, finish;
    std::cin >> start.col >> start.row >> finish.col >> finish.row;
    for (int i = 0; i < rows * cols; ++i){
        std::cin >> field[i];
        field[i] = (field[i] ? WALL : FREE);
    }
    field[start.row * cols + start.col] = 0;
    std::cout << BFS(field, start, finish, rows, cols);
    return 0;
}

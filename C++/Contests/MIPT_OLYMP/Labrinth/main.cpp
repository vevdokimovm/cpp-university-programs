#include <iostream>
#define WALL -1
#define FREE -2
struct Point
{
    int row;
    int col;
};

int algorithmLee(int * field, Point start, Point finish, int rows, int cols)
{
    int counter = 0;
    int sides_col[] = {1, 0, -1, 0};
    int sides_row[] = {0, 1, 0, -1};
    bool stop = true;
    field[cols * start.row + start.col] = 0;
    do {
        stop = true;
        for (int i = 0; i < rows * cols; ++i)
                if (field[i] == counter)
                    for (int sides = 0; sides < 4; ++sides)
                    {
                        int rows_i = (i / cols) + sides_row[sides];
                        int cols_i = (i % cols) + sides_col[sides];
                        if (rows_i >= 0 && rows_i < rows && cols_i >= 0 && cols_i < cols && field[rows_i * cols + cols_i] == FREE){
                            stop = false;
                            field[rows_i * cols + cols_i] = counter + 1;
                        }
                    }
            ++counter;
    } while (!stop && field[finish.row * cols + finish.col] == FREE);
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
    std::cout << algorithmLee(field, start, finish, rows, cols);
    return 0;
}

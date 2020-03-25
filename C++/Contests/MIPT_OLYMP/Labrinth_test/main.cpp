#include <iostream>
#include <iomanip>
#define WALL -1
#define FREE -2
#define info(msg, value) cout << msg " = " << value << endl;
using namespace std;

struct Point
{
    int row;
    int col;
};

int algorithmLee(int * field, Point start, Point finish, int rows, int cols)
{
    int counter = 0;
    int dcols[] = {1, 0, -1, 0};
    int drows[] = {0, 1, 0, -1};
    bool is_wall = true;
    if (field[start.row * cols + start.col] == -1 || field[finish.row * cols + finish.col] == -1)
        return 200;
    field[cols * start.row + start.col] = 0;
    do {
        is_wall = true;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (field[i * cols + j] == counter)
                {
                    for (int s = 0; s < 4; ++s)
                    {
                        int rowsi = i + drows[s];
                        int colsi = j + dcols[s];
                        if (rowsi >= 0 && rowsi < rows && colsi >= 0 && colsi < cols && field[rowsi * cols + colsi] == FREE){
                            is_wall = false;
                            field[rowsi * cols + colsi] = counter + 1;
                        }
                    }
                }
            }
        }
        ++counter;
        info("counter", counter);
    } while (!is_wall && field[finish.row * cols + finish.col] == FREE);
    if (field[finish.row * cols + finish.col] == FREE)
        return 100;
    return field[finish.row * cols + finish.col];
}

int main()
{
    int cols = 0, rows = 0;
    cin >> cols >> rows;
    int field[rows * cols] = {};
    Point start, finish;
    cin >> start.col >> start.row >> finish.col >> finish.row;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> field[i * cols + j];
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            if (field[i * cols + j])
                field[i * cols + j] = WALL;
            else
                field[i * cols + j] = FREE;
        }
    }
    cout << algorithmLee(field, start, finish, rows, cols) << endl;
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j)
            cout << setw(3) << field[i * cols + j] << " ";
        cout << endl;
    }
    return 0;
}


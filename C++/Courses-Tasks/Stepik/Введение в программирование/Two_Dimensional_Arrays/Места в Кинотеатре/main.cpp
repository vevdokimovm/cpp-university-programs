#include <iostream>

using namespace std;

int main()
{
    unsigned char rows = 0, cols = 0, free_rows = 0;
    cin >> rows >> cols;
    bool cinema[rows][cols];
    for (size_t i = 0; i < rows; ++i){
        for (size_t j = 0; j < cols; ++j){
            cin >> cinema[i][j];
        }
    }
    cin >> free_rows;
    for (size_t i = 0; i < rows; ++i){
        unsigned char counter = 0;
        for (size_t j = 0; j < cols; ++j){
            if (cinema[i][j])
                counter = 0;
            else {
                ++counter;
                if (counter == free_rows)
                    break;
            }
        }
        if (counter == free_rows){
            cout << i + 1 << free_rows;
            return 0;
        }
    }
    cout << 0 << free_rows;
    return 0;
}


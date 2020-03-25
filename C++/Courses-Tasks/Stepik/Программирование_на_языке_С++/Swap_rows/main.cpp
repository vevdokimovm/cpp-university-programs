#include <iostream>

using namespace std;

void swap_min(int *m[], unsigned rows, unsigned cols){
    int min_ar = m[0][0], index = 0;
    for (size_t i = 0; i != rows; ++i){
        for (size_t j = 0; j != cols; ++j){
            if (m[i][j] < min_ar){
                min_ar = m[i][j];
                index = i;
            }
        }
    }
    int * swapper = m[0];
    m[0] = m[index];
    m[index] = swapper;
}

int main()
{
    unsigned rows = 0;
    unsigned cols = 0;
    cin >> rows >> cols;
    int ** m = new int * [rows];
    m[0] = new int [cols * rows];
    for (size_t i = 1; i != rows; ++i)
        m[i] = m[i - 1] + cols;
    swap_min(m, rows, cols);
    for (size_t i = 0; i != rows; ++i){
        delete [] m[i];
    }
    delete [] m;
}

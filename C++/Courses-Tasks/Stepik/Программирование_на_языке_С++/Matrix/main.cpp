#include <iostream>

using namespace std;

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int ** ans = new int * [cols];
    for (unsigned i = 0; i != cols; ++i){
        ans[i] = new int [rows];
        for (unsigned j = 0; j != rows; ++j){
            ans[i][j] = m[j][i];
        }
    }
    return ans;
}

int main()
{
    unsigned rows = 0;
    unsigned cols = 0;
    cin >> rows >> cols;
    int ** m = new int * [rows];
    m[0] = new int [rows * cols];
    for (unsigned i = 1; i != rows; ++i)
        m[i] = m[i - 1] + cols;
    int ** f = transpose(m);

}

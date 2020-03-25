#include <iostream>
#include <fstream>
using namespace std;
typedef unsigned long long ull;
using u = unsigned;
int main()
{
    u rows = 0;
    u cols = 0;
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> rows >> cols;

    ull a[21][21] = {};

    for (size_t i = 1; i < rows + 1; ++i)
        for (size_t j = 1; j < cols + 1; ++j)
            fin >> a[i][j];

    for (size_t i = 0; i < 21; ++i)
        a[i][0] = 101;

    for (size_t i = 0; i < 21; ++i)
        a[0][i] = 101;

    a[1][0] = 0;
    for (size_t i = 1; i < rows + 1; ++i)
        for (size_t j = 1; j < cols + 1; ++j)
            a[i][j] += min(a[i - 1][j], a[i][j - 1]);

    fout << a[rows][cols];

    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;
#define FOR() \
for (size_t i = 2; i < rows + 2; ++i) \
    for (size_t j = 2; j < cols + 2; ++j)


int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    unsigned rows = 0;
    unsigned cols = 0;
    fin >> rows >> cols;
    unsigned a[rows + 2][cols + 2] = {};

    a[0][1] = 1;
    FOR() a[i][j] = a[i - 2][j - 1] + a[i - 1][j - 2];

    fout << a[rows + 1][cols + 1] << endl;

    return 0;
}

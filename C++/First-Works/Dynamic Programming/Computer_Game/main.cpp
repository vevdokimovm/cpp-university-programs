#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    short n, s;
    fscanf(fin, "%hd", &n);
    vector <short> a(n);
    for (int i = 0; i < n; i++){
        fscanf(fin, "%hd", &a[i]);
    }
    for (int i = 2; i < n; i++){
        short v1 = 3 * abs(a[i] - a[i - 2]);
        short v2 = a[i - 1] - a[i - 2];
        min(v1, v2) == v2 ? s = abs(a[i] - a[i - 1]) : s = 0;
        a[i] = min(v1, v2) + s;
    }
    short last = a.size() - 1;
    fprintf(fout, "%hd", a[last]);
    return 0;
}

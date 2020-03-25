#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, m, count;
    cin >> n >> m;
    char a[m][n];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
            if (a[i][j] >= 'A' && a[i][j] <= 'Z'){
                int num = a[i][j] - 'A';
                a[i][j] = 'a' + num;
            }
        }
    }
    for (int i = 0; i < n; i++){
        char compare = 'a';
        map<char, int> counter;
        for (int j = 0; j < m; j++){
            if (a[j][i] >= 'a' && a[j][i] <= 'z'){
                counter[a[j][i]] += 1;
            }
        }
    }
    return 0;
}

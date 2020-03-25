#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, k, a[20][20], correct = 0;
    cin >> n >> m;
    //Reading
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j ++){
            cin >> a[i][j];
        }
    }
    cin >> k;
    vector <int> b(k);
    for (int i = 0; i < n; i++){
        int lock_seats = 0;
        for (int j = 0; j < m; j ++){
            lock_seats += a[i][j];
        }
        while (correct != k && 0 <= (int)b.size() <= (int)a.size())

    }
    return 0;
}

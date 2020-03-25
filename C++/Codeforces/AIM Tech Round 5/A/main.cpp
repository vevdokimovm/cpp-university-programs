#include <iostream>
#define info(msg) cout << #msg << " = " << msg << endl;
using namespace std;

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;
    char a[n][m] = {};

    int first_B_row = 0;
    int col = 0;
    int side = 0;
    bool is_first = false;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j){
            char c = '\0';
            cin >> c;
            if (c == 'B' && !is_first){
                is_first = true;
                col = j;
                first_B_row = i;
            }
            if (c == 'B' && i == first_B_row)
                ++side;
                //info(side);
        }
    //info(first_B_row);
    //info(col);
    int value = side / 2;
    cout << first_B_row + value + 1 << ' ' << col + value + 1;
    return 0;
}

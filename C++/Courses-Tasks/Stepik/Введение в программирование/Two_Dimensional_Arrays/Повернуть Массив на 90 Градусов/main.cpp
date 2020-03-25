#include <iostream>

using namespace std;

int main()
{
    int n, m, a[100][100];
    cin >> n >> m;
    //Чтение
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    //Поворачивание
    for (int i = 0; i < m; i++){
        for (int j = n - 1; j >= 0; j--){
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}

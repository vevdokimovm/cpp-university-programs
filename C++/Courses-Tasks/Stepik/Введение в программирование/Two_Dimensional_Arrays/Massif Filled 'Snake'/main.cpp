#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, m, a[100][100], count = 0;
    cin >> n >> m;
    //Чтение
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            a[i][j] = 0;
        }
    }
    //Присваивание значений
    for (int i = 0; i < n; i++){
        int temp = m * (i + 1);
        count += m * (i % 2);
        for (int j = 0; j < m; j++){
            if (i % 2 == 0){
                count++;
                a[i][j] = count;
                //if (count >= )
                cout << setw(3) << a[i][j] << " ";
            }
            else {
                a[i][j] = temp;
                cout << setw(3) << a[i][j] << " ";
                temp--;
            }
        }
        cout << endl;
    }
    return 0;
}

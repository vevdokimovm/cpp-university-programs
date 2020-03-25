#include <iostream>
#include <vector>

/* Дано число n, не превосходящее 10, и массив размером n × n. Проверьте, является ли этот массив симметричным относительно главной диагонали. Выведите слово “YES”, если массив симметричный, и слово “NO” в противном случае.
Sample Input:
3
0 1 2
1 2 3
2 3 4
Sample Output:
YES
*/

using namespace std;

int main()
{
    int n, a[10][10];
    cin >> n;
    //Чтение
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    //Обработка правой и левой части
    vector <int> c;
    vector <int> b;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j > i){
                int temp = a[i][j];
                c.push_back(temp);
            }
            if (j < i){
                int temp = a[i][j];
                b.push_back(temp);
            }
        }
    }
    //Сравнение
    int count = 0;
    for (int i = 0; i < n; i++){
        if (c[i] == b[i]){
            count++;
        }
    }
    if (count == (int)c.size()){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}
//Не подощло по времени


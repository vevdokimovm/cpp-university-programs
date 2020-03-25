#include <iostream>
#include <vector>

/* Дан массив чисел. Выведите все элементы массива, которые больше предыдущего элемента .
Формат входных данных
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.
Формат выходных данных
Выведите ответ на задачу.
Sample Input:
5
1 5 2 4 3
Sample Output:
5 4
*/

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    //Reading
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //Treatment And Output
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] < a[i])
        {
            cout << a[i] <<" ";
        }
    }
    return 0;
}

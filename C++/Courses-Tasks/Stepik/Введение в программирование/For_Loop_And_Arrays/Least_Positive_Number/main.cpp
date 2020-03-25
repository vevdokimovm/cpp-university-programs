#include <iostream>
#include <vector>

/* Выведите значение наименьшего из всех положительных элементов в массиве. Известно, что в массиве есть хотя бы один положительный элемент.
Формат входных данных
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.
Формат выходных данных
Выведите ответ на задачу.
Sample Input:
5
5 -4 3 -2 1
Sample Output:
1
*/

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> a;
    //Reading
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp > 0)
        {
            a.push_back(temp);
        }
    }
    //Treatment
    int min = 0;
    for (int i = 1; i < (int)a.size(); i++)
    {
        if (a[min] >= a[i])
        {
            min = i;
        }
    }
    cout << a[min];
    return 0;
}

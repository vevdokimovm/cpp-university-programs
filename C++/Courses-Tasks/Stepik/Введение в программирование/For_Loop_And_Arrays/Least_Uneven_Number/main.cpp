#include <iostream>
#include <vector>
#include <cstdlib>

/* Выведите значение наименьшего нечетного элемента списка, а если в списке нет нечетных элементов - выведите число 0.
Формат входных данных
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.
Формат выходных данных
Выведите ответ на задачу.
Sample Input 1:
5
0 1 2 3 4
Sample Output 1:
1
Sample Input 2:
5
2 4 6 8 10
Sample Output 2:
0
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
        if (temp % 2 != 0)
        {
            a.push_back(temp);
        }
    }
    if (a.size() == 0)
    {
        cout << 0;
        exit(0);
    }
    //Treatment and Output
    int min = 0;
    for (int i = 1; i < (int)a.size(); i++)
    {
        if (a[min] >= a[i])
        {
            min = i;
        }
    }
    cout << a[min] << endl;
    return 0;
}

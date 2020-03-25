#include <iostream>
#include <vector>

/* Дан массив. Выведите те его элементы, которые встречаются в массиве только один раз. Элементы нужно выводить в том порядке, в котором они встречаются в списке.
Формат входных данных
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.
Формат выходных данных
Выведите ответ на задачу.
Sample Input 1:
6
1 2 2 3 3 3
Sample Output 1:
1
Sample Input 2:
8
4 3 5 2 5 1 3 5
Sample Output 2:
4 2 1
*/

using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;
    vector <int> a(n);
    vector <int> single_el;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == a[j])
            {
                count++;
            }
            if (i == n - 1 && count == 1)
            {
                single_el.push_back(a[j]);
                count = 0;
            }
            if (i == n - 1)
            {
                count = 0;
            }
        }
    }
    for (int i : single_el)
    {
        cout << i << " ";
    }
    return 0;
}

#include <iostream>
#include <vector>


/* Циклически сдвиньте элементы списка вправо (A[0] переходит на место A[1], A[1] на место A[2], ..., последний элемент переходит на место A[0]).
Формат входных данных
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.
Формат выходных данных
Выведите ответ на задачу.
Sample Input:
5
1 2 3 4 5
Sample Output:
5 1 2 3 4
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
    //Treatment
    /*
    begin = a[0];
    int temp;
    int temp2;
    temp = a[1];
    a[1] = a[0];
    temp2 = a[2];
    a[2] = temp;
    */
    int current = a[0];
    for (int i = 0; i < n; i++)
        {
            int j = (i + 1) % n;
            int temp = a[j];
            a[j] = current;
            current = temp;
        }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

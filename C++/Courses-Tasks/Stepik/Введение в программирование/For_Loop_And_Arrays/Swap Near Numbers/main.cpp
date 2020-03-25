#include <iostream>
#include <vector>

/* Переставьте соседние элементы массива (A[0] c A[1], A[2] c A[3] и т.д.). Если элементов нечетное число, то последний элемент остается на своем месте.
Формат входных данных
В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.
Формат выходных данных
Выведите ответ на задачу.
Sample Input:
5
1 2 3 4 5
Sample Output:
2 1 4 3 5
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
    for (int i = 0; i < n; i += 2)
    {
        if (i == n - 1)
        {
            break;
        }
        //Swap Places
        int temp;
        temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
    }
    //Output
    for (auto now : a){
        cout << now <<" ";
    }
    return 0;
}

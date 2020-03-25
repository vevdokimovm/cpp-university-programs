#include <iostream>
#include <algorithm>
#include <vector>

/*Отсортируйте массив.

Входные данные

Первая строка входных данных содержит количество элементов в массиве N ≤ 105. Далее идет N целых чисел, не превосходящих по абсолютной величине 109.

Выходные данные

Выведите эти числа в порядке неубывания.
Sample Input:
5
5 4 3 2 1
Sample Output:
1 2 3 4 5
*/

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> l(n);
    for (int i = 0; i < n; i++){
        cin >> l[i];
    }
    sort(l.begin(), l.end());
    for (vector<int>::const_iterator now = l.begin(); now != l.end(); now++){
        cout << *now << " ";
    }
    return 0;
}

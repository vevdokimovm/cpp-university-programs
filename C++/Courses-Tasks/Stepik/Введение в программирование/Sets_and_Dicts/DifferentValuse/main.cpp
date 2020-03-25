#include <iostream>
#include <set>

/* Дан список целых чисел, который может содержать до 100000 чисел. Определите, сколько в нем встречается различных чисел.

Входные данные

Вводится число N - количество элементов списка, а затем N чисел.

Выходные данные

Выведите ответ на задачу.

Sample Input:
5
1 2 3 2 1
Sample Output:
3
*/

using namespace std;

int main()
{
    set <int> j;
    int count = 0, n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int n;
        cin >> n;
        j.insert(n);
    }
    for (auto now = j.begin(); now != j.end(); now++){
        count++;
    }
    cout << count << endl;
    return 0;
}

#include <iostream>
#include <set>

/* ﻿Даны два списка чисел, которые могут содержать до 100000 чисел каждый. Посчитайте, сколько чисел содержится одновременно как в первом списке, так и во втором.

Входные данные

Вводится число N - количество элементов первого списка, а затем N чисел первого списка.

Затем вводится число M - количество элементов второго списка, а затем M чисел второго списка.

Выходные данные

Выведите ответ на задачу.

Sample Input:
3
1 3 2
3
4 3 2
Sample Output:
2
*/

using namespace std;

int main()
{
    set <int> s1;
    set <int> s2;
    int n, n1, count = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        s1.insert(x);
    }
    cin >> n1;
    for (int i = 0; i < n1; i++){
        int y;
        cin >> y;
        if (s1.find(y) != s1.end()){
            count++;
        }
        s2.insert(y);
    }
    cout << count << endl;
    return 0;
}

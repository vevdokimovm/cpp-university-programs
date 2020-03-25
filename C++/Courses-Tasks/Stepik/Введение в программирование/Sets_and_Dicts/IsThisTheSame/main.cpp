#include <iostream>
#include <set>

/* ¬о входной строке записана последовательность чисел через пробел. ƒл€ каждого числа выведите слово YES (в отдельной строке), если это число ранее встречалось в последовательности или NO, если не встречалось.

¬ходные данные

¬водитс€ число N - количество элементов списка, а затем N чисел.

¬ыходные данные

¬ыведите ответ на задачу.

Sample Input:
6
1 2 3 2 3 4
Sample Output:
NO
NO
NO
YES
YES
NO
*/

using namespace std;

int main()
{
    set <int> r;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int y;
        cin >> y;
        if (r.find(y) == r.end()){
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
        r.insert(y);
    }
    return 0;
}

#include <iostream>
#include <vector>

/* ƒана последовательность натуральных чисел, завершающа€с€ числом 0. ќпределите, какое наибольшее число подр€д идущих элементов этой последовательности равны друг другу. ≈сли не нашлось ни одной пары, тройки и т.д. элементов, равных друг другу, то программа должна вывести число 1.
‘ормат входных данных
¬водитс€ последовательность натуральных чисел, оканчивающа€с€ числом 0 (само число 0 в последовательность не входит, а служит как признак ее окончани€).
‘ормат выходных данных
¬ыведите ответ на задачу.
Sample Input:
1
7
7
9
1
0
Sample Output:
2
*/

using namespace std;

int main()
{
    int now, count = 1, same = 0;
    cin >> now;
    vector <int> a;
    while (now != 0) {
        if (now == same) {
            count++;
        } else {
            a.push_back(count);
            count = 1;
        }
        same = now;
        cin >> now;
    }
    a.push_back(count);
    int num_max = a[0];
    for (int i = 0; i < (int)a.size(); i++) {
        if (num_max < a[i]){
            num_max = a[i];
        }
    }
    cout << num_max << endl;
    return 0;
}

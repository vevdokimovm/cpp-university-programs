#include <iostream>

/* Дано действительное положительное число a и целоe число n.

Вычислите an. Решение оформите в виде рекурсивной функции power(a, n).

Формат входных данных
Вводится действительное положительное число a и целоe число n.
Формат выходных данных
Выведите ответ на задачу.
Sample Input 1:
2
1
Sample Output 1:
2
Sample Input 2:
2
2
Sample Output 2:
4
*/

using namespace std;

double power(double c, int y){
    if (y == 0){
        return 1;
    }
    else if (y > 0){
        return c * power(c, y - 1);
    }
    else {
        return 1 / c * power (c, y + 1);
    }
}

int main()
{
    int n;
    double a;
    cin >> a >> n;
    cout << power(a, n) << endl;
    return 0;
}

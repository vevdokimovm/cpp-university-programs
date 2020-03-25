#include <iostream>
#include <cmath>

/* Даны четыре действительных числа: x1, y1, x2, y2. Напишите функцию distance(x1, y1, x2, y2), вычисляющую расстояние между точкой (x1. y1) и (x2, y2). Считайте четыре действительных числа и выведите результат работы этой функции.

Формат входных данных
Вводятся четыре действительных числа.
Формат выходных данных
Выведите ответ на задачу.
Sample Input:
0
0
1
1
Sample Output:
1.41421
*/

using namespace std;

double distance(double a, double b, double c, double d){
    if (a == c && b == d){
        return 0;
    }
    if (a == c){
        return abs(b - d);
    } else if (b == d){
        return abs(a - c);
    }
    double ans = sqrt(pow(a - c, 2) + pow(b - d, 2));
    return ans;
}

int main()
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << distance(x1, y1, x2, y2) << endl;
    return 0;
}

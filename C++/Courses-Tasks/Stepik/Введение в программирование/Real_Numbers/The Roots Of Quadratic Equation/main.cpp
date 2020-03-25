#include <iostream>
#include <cmath>

/*Даны действительные коэффициенты a, b, c, при этом a ≠ 0 . Решите квадратное уравнение ax2 + bx + c = 0 и выведите все его корни.

Формат входных данных
Вводятся три действительных числа.
Формат выходных данных
Если уравнение имеет два корня, выведите два корня в порядке возрастания, если один корень — выведите одно число, если нет корней — не выводите ничего.
Sample Input:
1
-1
-2
Sample Output:
-1 2
*/

using namespace std;

int main()
{
    double a, b, c, x, x1, D, D_2;
    cout << "If your equation look like that : ax^2 +- bx +- c = 0, so write down a  b  c " << endl;
    cin >> a >> b >> c;
    D = b*b - 4 * a * c;
    if (D < 0)
    {
        cout << " ";
    }
    else if (D == 0)
    {
        x = -b / (2*a);
        cout << x;
    }
    else if (D > 0)
    {
        D_2 = sqrt(D);
        x = (-b + D_2) / (2*a);
        x1 = (-b - D_2) / (2*a);
        if (x > x1)
        {
            cout << x1 <<" "<< x;
        }
        else
        {
            cout << x << " " << x1;
        }
    }
    return 0;
}

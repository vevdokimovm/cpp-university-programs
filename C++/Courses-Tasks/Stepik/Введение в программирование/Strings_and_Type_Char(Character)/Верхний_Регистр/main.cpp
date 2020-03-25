#include <iostream>

/* Переведите символ в верхний регистр.

Входные данные

Вводится единственый символ.

Выходные данные

Если введеный символ является строчной буквой латинского алфавита, то выведите такую же заглавную букву. В противном случае выведите тот же символ, который был введен.

Sample Input:
b
Sample Output:
B
*/

using namespace std;

int main()
{
    char a;
    cin >> a;
    if (a >= 'a' && a <= 'z') {
        char al_num = a - 'a';
        char ans = 'A' + al_num;
        cout << ans;
    } else {
        cout << a;
    }
    return 0;
}

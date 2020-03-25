#include <iostream>

/* Вводится один символ, измените его регистр. То есть, если была введена строчная буква - сделайте ее заглавной и наоборот. Символы, не являющиеся латинской буквой, нужно выводить без изменений.

Входные данные

Вводится единственый символ.

Выходные данные

Выведите ответ на задачу.

Sample Input:
b
Sample Output:
B
*/

using namespace std;

int main()
{
    char k, al_num, ans;
    cin >> k;
    if (k >= 'a' && k <= 'z'){
        al_num = k - 'a';
        ans = 'A' + al_num;
        cout << ans;
    } else if (k >= 'A' && k <= 'Z'){
        al_num = k - 'A';
        ans = 'a' + al_num;
        cout << ans;
    } else {
        cout << k;
    }
    return 0;
}

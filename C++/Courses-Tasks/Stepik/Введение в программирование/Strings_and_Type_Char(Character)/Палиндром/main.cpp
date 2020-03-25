#include <iostream>
#include <string>

/* ѕо данной строке определите, €вл€етс€ ли она палиндромом (то есть, читаетс€ одинаково как слева-направо, так и справа-налево).
¬ходные данные

Ќа вход подаетс€ 1 строка без пробелов.
¬ыходные данные

Ќеобходимо вывести yes, если строка €вл€етс€ палиндромом, и no в противном случае.

Sample Input:
kayak
Sample Output:
yes
*/

using namespace std;
#include <cstdio>
int main()
{
    string g;
    cin >> g;
    int size = (int)g.size() - 1, count = 0;
    for (int i = 0; i < (int)g.size() / 2; i++){
        if (g[i] == g[size]){
            count++;
            size--;
        } else {
            break;
        }
    }
    if (count == (int)g.size() / 2){
        cout << "yes";
    } else {
        cout << "no";
    }
}

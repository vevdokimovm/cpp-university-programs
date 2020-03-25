#include <iostream>
#include <utility>
#include <vector>
#include <map>

using namespace std;

int main()
{
    short n, comp = 1, begin, parent, v_num = 2;
    cin >> n;
    short siz = n - 1;
    vector <short> sons(siz, 0);
    for (short i = 0; i < siz; i++){
        cin >> parent;
        if (parent == comp){
            sons[comp]++;
            v_num++;
        } else {
            begin = v_num - sons[comp];
            if (parent >= begin && parent < v_num)
            {
                sons[comp]--;
            }
            comp = parent;
            sons[comp]++;
            v_num++;
        }
    }
    for (short i = 0; i < siz; i++){
        if ((sons[i] >= 3) || (sons[i] == 0)){
            continue;
        } else {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}

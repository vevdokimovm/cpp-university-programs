#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    long long n, k, desk_peter, row_peter, place;
    cin >> n >> k >> desk_peter >> row_peter;
    long long petr_nomer = desk_peter * 2 - row_peter % 2;
    long long next = petr_nomer + k;
    long long prev = petr_nomer - k;
    if (next <= n){
        place = next;
    } else if (prev > 0){
        place = prev;
    } else {
        cout << -1;
        exit(0);
    }
    short row = place % 2 == 0 ? 2 : 1;
    cout << (place + 1) / 2 << " " << row;
    return 0;
}
 /* if (petr_nomer + k <= n){
        short row = (petr_nomer + k) % 2;
        if (row == 0){
            row = 2;
        }
        cout << (petr_nomer + k + 1) / 2 << " " << row;
    } else if (petr_nomer - k > 0){
        short row = (petr_nomer - k) % 2;
        if (row == 0){
            row = 2;
        }
        cout << (petr_nomer - k + 1) / 2 << " " << row;
    } else {
        cout << -1;
    }*/



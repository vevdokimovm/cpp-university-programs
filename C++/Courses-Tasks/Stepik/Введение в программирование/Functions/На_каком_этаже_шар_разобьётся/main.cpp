#include <iostream>

using namespace std;

int binary_search(int a, int r){
    if (a == 1){
        return 0;
    }
    if (a % 2 == 1){
        return 1 + binary_search(a / 2 + 1, 1);
    }
    return 1 + binary_search(a / 2, 1);
}

int main()
{
    int a;
    cin >> a;
    cout << binary_search(a, 1) << endl;
    return 0;
}

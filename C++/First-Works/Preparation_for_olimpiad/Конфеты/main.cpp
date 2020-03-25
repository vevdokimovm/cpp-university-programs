#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    unsigned int a, b, c, count = 0;
    cin >> a >> b >> c;
    if (a == 0){
        cout << 0;
        exit(0);
    } else if (b == 0){
        cout << 1;
        exit(0);
    } else if (c == 0){
        cout << 2;
        exit(0);
    }
    while (a != 0 && b != 0 && c != 0){
        if (count % 4 == 3){
            b--;
            a--;
            count += 2;
        } else if (count % 4 == 1) {
            b--;
            c--;
            count += 2;
        } else {
            a--;
            b--;
            c--;
            count += 3;
        }
    }
    cout << count << endl;
    return 0;
}

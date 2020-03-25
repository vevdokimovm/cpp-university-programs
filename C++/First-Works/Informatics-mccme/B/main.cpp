#include <iostream>
#define info(msg) cout << #msg << " = " << msg << endl;

using namespace std;

using u = unsigned;

struct Shkololo {
    u next;
    u holes = 0;
};

void clear_holes(Shkololo a[], u n){
    for (size_t i = 0; i < n; ++i)
        a[i].holes = 0;
}

int main()
{
    u n = 0;
    cin >> n;

    Shkololo a[n] = {};
    for (size_t i = 0; i < n; ++i){
        cin >> a[i].next;
        --a[i].next;
    }

    for (size_t i = 0, j = i; i < n; ++i, j = i){
        while(true){
            ++a[j].holes;
            if (a[j].holes == 2)
                break;
            j = a[j].next;
        }
        cout << j + 1 << " ";
        clear_holes(a, n);
    }
    return 0;
}

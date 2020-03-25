#include <iostream>
#include <algorithm>
#define info(msg) cout << #msg << " = " << msg << endl;

using namespace std;
using ull = unsigned long long;

struct Student {
    int eng;
    int nem;
    int math;
    int history;
    int id;
};

bool cmp(Student a, Student b){
    if (a.eng + a.nem + a.math + a.history == b.eng + b.nem + b.math + b.history)
        return a.id < b.id;
    else
        return a.eng + a.nem + a.math + a.history > b.eng + b.nem + b.math + b.history;
}

void find_element(Student a[], unsigned n){
    for (size_t i = 0; i < n; ++i)
        if (a[i].id == 1){
            cout << i + 1;
            return;
    }
}

int main()
{
    unsigned n = 0;
    cin >> n;
    Student a[n];
    for (size_t i = 0, id = 1; i < n; ++i, ++id){
        cin >> a[i].eng >> a[i].nem >> a[i].math >> a[i].history;
        a[i].id = id;
    }
    sort(a, a + n, cmp);

    find_element(a, n);


    /*cout << endl;
    for (size_t i = 0; i < n; ++i)
        cout << a[i].eng << ' ' << a[i].nem << ' ' << a[i].math << ' ' << a[i].history << endl;*/
    return 0;
}

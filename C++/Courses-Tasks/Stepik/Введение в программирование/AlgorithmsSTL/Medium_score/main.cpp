#include <iostream>
#include <algorithm>

using namespace std;

struct kid
{
    string surname;
    string name;
    int score;
};

bool cmp(kid a, kid b){
    return a.score > b.score;
}

int main()
{
    int n = 0;
    cin >> n;
    vector <kid> a(n);
    for (int i = 0; i < n; ++i)
    {
        int m1 = 0, m2 = 0, m3 = 0;
        kid kido;
        cin >> a[i].surname >> a[i].name >> m1 >> m2 >> m3;
        a[i].score = m1 + m2 + m3;
    }
    stable_sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; ++i)
        cout << a[i].surname << " " << a[i].name << endl;
    return 0;
}

#include <iostream>
#include <iomanip>
#include <algorithm>

#define info(msg) cout << #msg << " = " << msg << endl;
#define FOR(n) \
for (size_t i = 0; i < n; ++i)


using namespace std;
using ull = unsigned long long;
using ll = long long;

struct Object {
    ull cost;
    ull weight;
    double c_per_kg;
};

ostream& operator<<(ostream& os, Object object){
    os << object.cost << ' ' << object.weight << ' ' << object.c_per_kg;
    return os;
}

bool cmp(Object o1, Object o2){
    return o1.c_per_kg > o2.c_per_kg;
}

int main()
{
    ull n = 0;
    ull w = 0;
    cin >> n >> w;
    Object objects[n] = {};

    FOR(n){
        Object& object = objects[i];
        cin >> object.cost >> object.weight;
        object.c_per_kg = static_cast<double>(object.cost) / object.weight;
    }

    sort(objects, objects + n, cmp);

    double money = 0.0;

    FOR(n){
        Object current = objects[i];
        if (current.cost)
            while (w > 0 && current.weight > 0){
                --current.weight;
                money += current.c_per_kg;
                --w;
            }
        if (w <= 0)
            break;
    }
    //cout.precision(3);
    cout << fixed << setprecision(3) << money;

    //FOR(n)
    //    cout << objects[i] << endl;

    return 0;
}

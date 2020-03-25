#include <iostream>
#include <algorithm>
#include <vector>
#define FOR(n) \
for (size_t i = 0; i < n; ++i)


using namespace std;
using ll = long long;

struct Segment {
    ll x1;
    ll x2;
};

bool cmp(Segment s1, Segment s2){
    return s1.x2 < s2.x2;
}

int main() {
    int n = 0;
    cin >> n;
    Segment segments[n] = {};
    FOR(n)
        cin >> segments[i].x1 >> segments[i].x2;

    sort(segments, segments + n, cmp);

    ll cnt = 0;
    vector<ll> dots;
    ll last_right_coord = -1;

    //Greedy algorithm
    FOR(n){
        Segment current = segments[i];
        if (current.x1 > last_right_coord){
            ++cnt;
            last_right_coord = current.x2;
            dots.push_back(current.x2);
        }
    }

    //Output
    cout << cnt << endl;
    FOR(dots.size())
        cout << dots[i] << ' ';

    return 0;
}

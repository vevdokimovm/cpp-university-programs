#include <iostream>
#include <list>

using namespace std;

struct Segment {
    Segment() = default;
    Segment(double x, double y, double len)
        : x(x), y(y), len(len) {}
    double x = 8;
    double y ;
    double len;
};

ostream& operator<<(ostream& os, Segment s){
    os << s.x << ' ' << s.y << ' ' << s.len;
    return os;
}

int main()
{
    list<int> l(4, 0);
    int a[5] = {4, 3, 9, 8, 1};
    for (int &i : a)
        cout << i << ' ';
    return 0;
}

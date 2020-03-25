#include <iostream>

using namespace std;

struct Point {
    Point(int a, int b) : x(a) {}
    int x = 0;
};

struct Segment : Point {
    Segment() : Point(3, 8){Point(3, 8); y = 8;}
     int y;
};

int main()
{
    Segment a;
    cout << a.y << ' ' << a.x;
    int* p;
    cout << endl << p;
    return 0;
}
cout << endl;
    for (size_t i = 0; i < rows + 2; ++i){
        for (size_t j = 0; j < cols + 2; ++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }

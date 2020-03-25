#include <iostream>
#include <cmath>
using namespace std;

class Rectangle
{
private :
    double x1, y1, x2, y2, a, b, P, S;
public :
    void SetCoord(double w, double i, double c, double d){
        x1 = w;
        y1 = i;
        x2 = c;
        y2 = d;
        a = abs(x2 - x1);
        b = abs(y2 - y1);
        P = 2 * (a + b);
        S = a * b;
    }
    double Side_a(){
        return a;
    }
    double Side_b(){
        return b;
    }
    double Perimetr(){
        return P;
    }
    double Area(){
        return S;
    }
};

int main()
{
    Rectangle a;
    int j, b, c, d, x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    a.SetCoord(x1, y1, x2, y2);
    j = a.Side_a();
    b = a.Side_b();
    c = a.Perimetr();
    d = a.Area();
    cout << "A = " << j << " " << "B = " << b << " " << "P = " << c << " " << "S = " << d;
    return 0;
}

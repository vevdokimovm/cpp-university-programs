#include "triangle.h"
#include <iostream>
#include <cmath>
using namespace std;

 void triangle::set_points(double a, double b, double c, double d, double e, double f)
    {
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;
        x3 = e;
        y3 = f;
    }
    bool triangle::existence(){
        return (y1 == y2 && y2 == y3 && x1 == x2 && x2 == x3 && y1 == y3 && x1 == x3);
    }
    void triangle::sides()
    {
        side_a = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
        side_b = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
        side_c = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
        cout << "a = " << side_a << " b = " << side_b << " c = " << side_c << endl;
    }
    void triangle::area()
    {
        double p = (side_a + side_b + side_c) / 2;
        area_ = sqrt(p * (p - side_a) * (p - side_b) * (p - side_c));
        cout << "S = " << area_;
    }

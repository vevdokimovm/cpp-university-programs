#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Circle
{
    double radiusP2;
    double a;
    double b;
};

struct Point
{
    Point () {};
    Point(double x, double y)
        : x(x), y(y) {}
    double x;
    double y;
};

Circle CircleTriangle(Point p1, Point p2, Point p3)
{
    Circle circle4;
    double x = (((p1.x * p1.x) / (2 * (p1.y - p2.y))) - ((p1.x * p1.x) / (2 * (p1.y - p3.y))) - ((p2.x * p2.x) / (2 * (p1.y - p2.y))) + ((p3.x * p3.x) / (2 * (p1.y - p3.y))));
    x += (((p1.y * p1.y) / (2 * (p1.y - p2.y))) - ((p1.y * p1.y) / (2 * (p1.y - p3.y))) - ((p2.y * p2.y) / (2 * (p1.y - p2.y))) + ((p3.y * p3.y) / (2 * (p1.y - p3.y))));
    x /= ((p1.x / (p1.y - p2.y)) - (p1.x / (p1.y - p3.y)) - (p2.x / (p1.y - p2.y)) + (p3.x / (p1.y - p3.y)));
    double y = (-2 * x * p1.x + 2 * x * p3.x + p1.x * p1.x - p3.x * p3.x + p1.y * p1.y - p3.y * p3.y) / (2 * (p1.y - p3.y));
    circle4.a = x;
    circle4.b = y;
    circle4.radiusP2 = (p3.x - circle4.a) * (p3.x - circle4.a) + (p3.y - circle4.b) * (p3.y - circle4.b);
    return circle4;
}


Circle newCircle3(Point * a2, Point p1, Point p2, size_t last_index)
{
    Circle circle3;
    circle3.radiusP2 = ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)) / 4;
    circle3.a = (p1.x + p2.x) / 2;
    circle3.b = (p1.y + p2.y) / 2;
    for (size_t i = 0; i < last_index; ++i)
    {
        double circle_equation1 = (a2[i].x - circle3.a) * (a2[i].x - circle3.a) + (a2[i].y - circle3.b) * (a2[i].y - circle3.b);
        if (circle_equation1 > circle3.radiusP2)
            circle3 = CircleTriangle(a2[i], p1, p2);
    }
    return circle3;
}

Circle newCircle2(Point * a1, Point p1, size_t last_index)
{
    Circle circle2;
    circle2.a = (p1.x + a1[0].x) / 2;
    circle2.b = (p1.y + a1[0].y) / 2;
    circle2.radiusP2 = ((p1.x - a1[0].x) * (p1.x - a1[0].x) + (p1.y - a1[0].y) * (p1.y - a1[0].y)) / 4;
    for (size_t i = 1; i < last_index; ++i)
    {
        double circle_equation1 = (a1[i].x - circle2.a) * (a1[i].x - circle2.a) + (a1[i].y - circle2.b) * (a1[i].y - circle2.b);
        if (circle_equation1 > circle2.radiusP2)
            circle2 = newCircle3(a1, a1[i], p1, i);
    }
    return circle2;
}

Circle minRadius1(Point * a, unsigned short points)
{
    Circle circle1;
    circle1.a = (a[1].x + a[0].x) / 2;
    circle1.b = (a[1].y + a[0].y) / 2;
    circle1.radiusP2 = ((a[1].x - a[0].x) * (a[1].x - a[0].x) + (a[1].y - a[0].y) * (a[1].y - a[0].y)) / 4;
    for (size_t i = 2; i < points; ++i)
    {
        double circle_equation = (a[i].x - circle1.a) * (a[i].x - circle1.a) + (a[i].y - circle1.b) * (a[i].y - circle1.b);
        if (circle_equation > circle1.radiusP2)
            circle1 = newCircle2(a, a[i], i);
    }
    return circle1;
}

int main()
{
    unsigned short peaks = 0;
    cin >> peaks;
    Point polygon[peaks];
    for (size_t i = 0; i < peaks; ++i)
        cin >> polygon[i].x >>  polygon[i].y;
    Circle answer = minRadius1(polygon, peaks);
    cout << fixed << setprecision(3) << answer.a << " " << answer.b << " " << sqrt(answer.radiusP2);
    return 0;
}

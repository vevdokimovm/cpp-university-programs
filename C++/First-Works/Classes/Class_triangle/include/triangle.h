#ifndef TRIANGLE_H
#define TRIANGLE_H

class triangle
{
private:
    double x1, y1, x2, y2, x3, y3, side_a, side_b, side_c, area_;
public:
    void set_points(double, double, double, double, double, double);
    void sides();
    bool existence();
    void area();
};

#endif // TRIANGLE_H

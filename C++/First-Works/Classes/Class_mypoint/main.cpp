#include <iostream>
#include <cmath>

using namespace std;

class MyPoint
{
private :
    string c;
    char n;
    double x, y;
public :
    void SetPoint(string s, char g, double b, double u)
    {
        c = s;
        n = g;
        x = b;
        y = u;
    }
    double Distance(){
        return sqrt(x * x + y * y);
    }
    double Retrun_x(){
        return x;
    }
    double Return_y(){
        return y;
    }
    int Term(){
        if (x > 0 && y > 0)
            return 1;
        else if (x > 0 && y < 0)
            return 4;
        else if (x < 0 && y > 0)
            return 2;
        else if (x < 0 && y < 0)
            return 3;
        else
            return 5;
    }
    void ShowPoint()
    {
        cout << c << " " << n << "(" << x << "; " << y << ")" << endl;
    }
};

int main()
{
    MyPoint a;
    cin >> k >> f >> ;
    int m;
    double l, j;
    a.SetPoint("Georgia", 'A', 7, 8);
    a.ShowPoint();
    l = a.Distance();
    j = a.Return_y();
    m = a.Term();
    cout << "Dist = " << l << " Y = "<< j << " Term = " << m;
    return 0;
}

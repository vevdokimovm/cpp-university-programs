#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    double a = 1, b = 1, c = 1, n;
    scanf("%lf/", &a);
    n = scanf("%lf/%lf", &b, &c);
    if (n == 2){
        printf("%f", a + b / c);
    } else if (n == 1){
        printf("%f", a / b);
    } else {
        printf("%f", a);
    }
    return 0;
}

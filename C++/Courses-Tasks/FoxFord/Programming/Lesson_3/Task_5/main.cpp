#include <cstdio>

using namespace std;

int main()
{
    int a, b, c, d;
    char c1, c2, c3, l;
    scanf("%i%c%i%c%i%c%i%c", &a, &c1, &b, &c2, &c, &c3, &d, &l);
    (a >= 0 && a <= 255 && b >= 0 && b <= 255 && c >= 0 && c <= 255 && d >= 0 && d <= 255 && l == '' && c1 == '.' && c2 == '.' && c3 == '.') ?
    printf("YES") : printf("NO");
    return 0;
}

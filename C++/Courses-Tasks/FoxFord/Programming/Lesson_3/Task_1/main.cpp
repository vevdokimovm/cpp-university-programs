#include <cstdio>

using namespace std;

int main()
{
    char t;
    int h, m;
    scanf("%d:%d %c.m.", &h, &m, &t);
    if (t == 'p' && (int)h != 12){
        printf("%02d:%02d", h + 12, m);
    } else if ((int)h == 12 && t == 'a'){
        printf("%02d:%02d", 0, m);
    } else {
        printf("%02d:%02d", h, m);
    }
    return 0;
}

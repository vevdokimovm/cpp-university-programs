#include<stdio.h>

int main()
{
    int n, sum;
    scanf("%d", &n);
    sum = n;
    while(scanf(",%d", &n) == 1)
        sum += n;
    printf("%d\n", sum);
    return 0;
}

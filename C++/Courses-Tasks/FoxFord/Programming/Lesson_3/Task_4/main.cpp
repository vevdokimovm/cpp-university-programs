#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    double max = 0;
    int n, r = 0;
    scanf("%d", &n);
    vector <double> b(n);
    for (int i = 0; i < n; i++){
        scanf("%lf", &b[i]);
        if (b[i] > max){
            max = b[i];
        }
    }
    if (max >= 1 || max <= -1){
        while (max > 0){
            max = (int)max / (int)10;
            r++;
        }
    }
    for (auto now : b){
        printf("%*.2f\n", r + 3, now);
    }
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int m, d, dif_m, m_[12], d_[122];
    cin >> m >> d;
    int temp = d;
    dif_m = 12 - m;
    while (m <= 12){
        if (m % 2 == 0){
            temp += 7;
            d_.push_back(temp);
            m_.push_back(m);
        }
    }
    cout << << endl;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> a = {4232, 5768, 848, 4425, 6118, 4922, 4656, 8005, 843, 6949, 188, 5166, 4973, 275, 4453, 5732, 3931, 9997, 2751, 9157};
    vector <int> b;
    int sum = 0;
    while (sum <= 100000){
        for (int i = 0; i < (int)a.size(); i++){
            int max = max_element(a, a+20);
            sum += max;
            b.push_back(max);
            a.erase(max);
        }
    }
    for (auto now : b){
        cout << now << " ";
    }
    cout << "\n" << sum;
    return 0;
}

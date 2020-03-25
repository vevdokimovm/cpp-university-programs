#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int r, c, count = 0, max_dif = 0;
    cin >> r >> c;
    vector <int> brigada;
    vector <int> height(r * c);
    for (int i = 0; i < r * c; i++){
        cin >> height[i];
    }
    sort(height.begin(), height.end());
    for (int i = 0; i < r * c; i++){
        brigada.push_back(height[i]);
        count++;
        if (count == c){
            for (unsigned i = 0; i < brigada.size(); i++){
                for (unsigned j = i + 1; j < brigada.size(); j++){
                if (abs(brigada[i] - brigada[j]) > max_dif){
                    max_dif = abs(brigada[i] - brigada[j]);
                    }
                }
            }
            brigada.clear();
            count = 0;
        }
    }
    cout << max_dif << endl;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int Max(vector<int> arr){
    int highest = arr[0];
    for (int i = 1; i < (int)arr.size(); i++){
        if (arr[i] > highest){
            highest = arr[i];
        }
    }
    return highest;
}

int main()
{
    vector<int> b = {1, 2, 3, 133, 5, 1, 13};
    cout << Max(b) << endl;
    return 0;
}

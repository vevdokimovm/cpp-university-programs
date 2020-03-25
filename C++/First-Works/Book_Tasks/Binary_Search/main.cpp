#include <iostream>
#include <vector>

using namespace std;

int Binary_Search(vector<int> arr, int item){
    int low = 0;
    int high = (int)arr.size() - 1;
    while (low <= high){
        int mid = (low + high) / 2;
        int guess = arr[mid];
        if (guess == item) {
            return mid;
        } else if (guess > item) {
            high = mid - 1;
        } else if (guess < item) {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int a, now;
    cin >> a;
    vector <int> b;
    while (now != 0){
        cin >> now;
        b.push_back(now);
    }
    cout << Binary_Search(b, a) << endl;
    return 0;
}

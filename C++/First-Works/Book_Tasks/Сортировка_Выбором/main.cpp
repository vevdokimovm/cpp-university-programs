#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int Smallest_Index(vector<int> arr){
    int smallest = arr[0];
    int smallest_index = 0;
    for (int i = 1; i < (int)arr.size(); i++){
        if (arr[i] < smallest){
            smallest = arr[i];
            smallest_index = i;
        }
    }
    return smallest_index;
}

vector<int> SelectionSort(vector<int> arr){
    vector<int> newArr;
    for (int i = 0; i < (int)arr.size(); i++){
        int smallest = Smallest_Index(arr);
        newArr.push_back(smallest);
        arr.erase(arr.begin() + smallest);
    }
    return newArr;
}

int main()
{
    vector <int> b = {5, 3, 6, 2, 10};
    copy(SelectionSort(b).begin(), SelectionSort(b).end(), ostream_iterator<int>(cout, " "));
    return 0;
}

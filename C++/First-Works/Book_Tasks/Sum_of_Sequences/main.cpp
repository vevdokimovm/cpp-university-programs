#include <iostream>
#include <vector>

using namespace std;

int SumSequence(vector<int> vector, int count){
    if (count >= (int)vector.size()){
        return 0;
    }
    return vector[count] + SumSequence(vector, count + 1);
}

int main()
{
    int a, count = 0;
    vector <int> b;
    while (a != 0){
        cin >> a;
        b.push_back(a);
    }
    cout << SumSequence(b, count) << endl;
    return 0;
}

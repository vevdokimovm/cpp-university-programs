#include <iostream>
#include <vector>

using namespace std;

int SumSequence(){
    int a;
    cin >> a;
    if (a != 0) return a + SumSequence();
}

int main()
{
    cout << SumSequence();
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << " n = ";
    cin >> n;
    int size = n+1;
    int *a = new int[size];
    for (int i = 0; i < size; i++)
        a[i] = i;
    for (int p = 2; p < size; p++)
    {
        if (a[p] != 0)
        {
        cout << a[p] << endl;
        for (int j = p*p; j < size; j += p)
            a[j] = 0;
        }
    }
    //cin.get(); cin.get();
}

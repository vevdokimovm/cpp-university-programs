#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    string x, z;
    cin >> x >> z;
    int x_size = x.size(), z_size = z.size();
    //Case - print nothing
    if (x.find(z) != string::npos){
        int n = x.find(z);
        while (x.find(z, n + 1) != string::npos)
            n = x.find(z, n + 1);
        if (n == z_size - x_size){
            return 0;
        }
    //Same case
    } else if (z.find(x) != string::npos){
        int n = z.find(x);
        while (z.find(x, n + 1) != string::npos)
            n = z.find(x, n + 1);
        if (n == z_size - x_size){
            return 0;
        }
    }
    //Case - print some letters
    else {
        while (x < z){
            x += x;
        }
        cout << x;
    }
    cout << 55;
}

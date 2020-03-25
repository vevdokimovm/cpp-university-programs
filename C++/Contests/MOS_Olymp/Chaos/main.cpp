#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fout.open("c:\\users\\home\\desktop\\output.txt");
    short n, count = 0, c;
    cin >> n;
    fout << n << "\n" << "\n";
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        count = 0;
        a.clear();
        cin >> c;
        fout << c << "\n";
    //Input of array
        for (int j = 0; j < c; j++){
            cin >> a[j];
            count++;
        }
        sort(a.begin(), a.end());
        int last = count - 1;
        swap(a[0],a[last]);
    //Output of array
        for (int k = 0; k < c; k++)
            fout << a[k] << " ";
        fout << "\n" << "\n";
    }
    return 0;
}

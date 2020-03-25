#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;
    vector <int> a(n);
    //Array of inappropriate numbers
    array<int, 100> simples = {11, 13, 17, 19, 22, 23, 26, 29, 31, 32, 33, 34, 37, 38, 39, 41, 43, 44, 46, 47, 50, 51, 52, 53, 55, 57, 58, 59, 61, 62, 65, 66, 67, 68, 69, 71, 73, 74, 75, 76, 77, 78, 79};
    int size_a = simples.size();
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        //Variable of simple numbers
        count = 0;
        if (a[i] > 818181){
            cout << "NO" << "\n";
            continue;
        }
        //Case - 3 digits or less
        else if (a[i] / 1000 == 0)
            cout << "YES" << "\n";
        //Case - 4 and 5 digits
        else if (a[i] / 100000 == 0){
            int n1 = a[i] % 100, n2 = (a[i] % 1000) / 10, n3 = (a[i] % 10000) / 100, n4;
            a[i] / 10000 == 0 ? n4 = -1 : n4 = a[i] / 1000;
            for (int k = 0; k < size_a; k++){
                if (n1 == simples[k] || n2 == simples[k] || n3 == simples[k] ||  n4 == simples[k]){
                    if ((n1 == n2 && n1 == n3) || (n1 == n2 && n1 == n3 && n1 == n4))
                        count += 3;
                    else if (n1 == n3 || n1 == n2 || n2 == n3 || n1 == n4 || n4 == n3 || n4 == n2)
                        count += 2;
                    else
                        count++;
                    }
            }
            if (count < 3 && n1 <= 81 && n2 <= 81 && n3 <= 81 && n4 <= 81)
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
        //Case 6 digits
        else {
            int n1 = a[i] % 100, n2 = (a[i] % 10000) / 100, n3 = a[i] / 10000;
            for (int y = 0; y < size_a; y++){
                if (n1 == simples[y] || n2 == simples[y] || n3 == simples[y]){
                    if (n1 == n2 && n2 == n3)
                        count += 3;
                    else if (n1 == n2 || n2 == n3 || n1 == n3)
                        count += 2;
                    else
                        count++;
                }
            }
                if (count < 3 && n1 <= 81 && n2 <= 81 && n3 <= 81)
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
    }
}

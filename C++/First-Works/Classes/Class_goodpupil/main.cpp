#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, counter = 0;
    cin >> n;
    vector <string> b(n);
    vector <string> g(n);
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    for (int i = 0; i < n; i++){
        int first, second, str_length = b[i].length();
        if (b[i].find_first_of("45") != string::npos){
            first = b[i].find_first_of("45");
            if (first == str_length - 3 && b[i].find_first_of("45", first + 1) != string::npos){
                second = b[i].find_first_of("45", first + 1);
                if (second == str_length - 2 && b[i].find_first_of("45", second + 1) != string::npos){
                    b[i].erase(first, 3);
                    g[counter] = b[i];
                    counter++;
                }
            }
        }
    }
    for (int j = 0; j < counter - 1; j++){
        cout << g[j] << endl;
    }
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    string s, s1;
    cin >> s >> s1;
    int counter = 0, s_size = s1.size(), ind = 0;

    ind = s.find(s1, ind);
    while (ind != string::npos){
        ind = s.find(s1, ind+ s_size);
        counter++;
    }
    cout << counter << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

char compare(string const & n1, string const & n2){
    if (n1.size() > n2.size())
        return '>';
    else if (n1.size() < n2.size())
        return '<';
    else {
        int last = n1.size();
        for (int i = 0; i < last; ++i)
            if (n1[i] > n2[i])
                return '>';
            else if (n1[i] < n2[i])
                return '<';
    }
    return '=';
}

int main(){
    string n1 = "";
    string n2 = "";
    cin >> n1 >> n2;
    //cout << compare(n1, n2);
    cout << 'h' + n1;
}

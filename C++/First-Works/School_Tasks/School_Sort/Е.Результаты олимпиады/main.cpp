#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

struct olimp {
    int id;
    int score;
};

bool comp(olimp c, olimp b){
    if (c.score == b.score){
        return c.id < b.id;
    }
    return c.score >= b.score;
}

int main(){
    int n;
    cin >> n;
    vector <olimp> a(n);
    for (int i = 0; i < n; i++){
        int temp, s_temp;
        cin >> temp >> s_temp;
        olimp struct_temp;
        struct_temp.id = temp;
        struct_temp.score = s_temp;
        a[i] = struct_temp;
    }
    cout << "\n";
    sort(a.begin(), a.end(), comp);
    for (auto now : a){
        cout << now.id << " " << now.score << "\n";
    }
}

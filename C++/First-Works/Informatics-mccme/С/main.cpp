#include <bits/stdc++.h>
using namespace std;

#define info(msg) cout << #msg << " = " << msg << endl;
#define print(a, n) \
for (int i = 0; i < n; ++i) \
    cout << a[i].cons << " " << a[i].money_to_switch << endl;

using ull = unsigned long long;

struct Voter {
    int cons;
    ull money_to_switch;
};

bool is_max(int* count_votes, int size_cv, int cons = 1){
    for (int i = 0; i < size_cv; ++i)
        if (count_votes[i] >= count_votes[cons] && i != cons)
            return false;
    return true;
}

void Fcount_votes(Voter a[], int size_a, int count_votes[]){
    for (int i = 0; i < size_a; ++i)
        count_votes[a[i].cons] = 0;
    for (int i = 0; i < size_a; ++i)
        ++count_votes[a[i].cons];
}

bool cmp(Voter a, Voter b){
    return a.money_to_switch < b.money_to_switch;
}

void find_low_cos_and_add_to_sum(Voter* a, int size_a, ull& sum, int& start_index){
     while(true){
        if (a[start_index].cons != 1){
            sum += a[start_index].money_to_switch;
            a[start_index].cons = 1;
            ++start_index;
            return;
        }
        ++start_index;
     }
}

int main(){
    int n = 0;
    int m = 0;
    cin >> n >> m;
    Voter a[n] = {};
    for (int i = 0; i < n; ++i)
        cin >> a[i].cons >> a[i].money_to_switch;

    int count_votes[m + 1] = {};
    ull sum = 0;
    Fcount_votes(a, n, count_votes);
    if (is_max(count_votes, m + 1)){
        cout << sum;
        return 0;
    }

    sort(a, a + n, cmp);

    int index = 0;
    while(!is_max(count_votes, m + 1)){
        find_low_cos_and_add_to_sum(a, n, sum, index);
        Fcount_votes(a, n, count_votes);
        //info(sum);
    }

    cout << sum;

    //cout << endl;
    //print(a, n);

}

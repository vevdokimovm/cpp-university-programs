//
// Created by Home on 23.08.2018.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(n) \
for (size_t i = 0; i < n; ++i)
#define info(msg) cout << #msg << " = " << msg << endl;
#define ainfo(m) \
cout << #m << endl; \
FOR(m.size()){ \
    cout << m[i] << endl; \
} \
cout << endl;

using namespace std;

struct Suit {
    int type;
    int increase;
};

ostream& operator<<(ostream& os, Suit s){
    os << s.type << ' ' << s.increase;
    return os;
}

istream& operator>>(istream& is, Suit s){
    is >> s.type >> s.increase;
    return is;
}

bool cmp1(int s1, int s2){
    return s1 > s2;
}

bool cmp2(Suit c1, Suit c2){
    return c1.increase > c2.increase;
}



int best(vector<Suit> items){
    if (items.empty())
        return -1;
    else
        return items[0].increase;
}

int sum(vector<int> items){
    int s = 0;
    for (size_t i = 0; i < items.size(); ++i)
        s += items[i];
    return s;
}


double optimal_speed(vector<int> speeds, vector<Suit> plavki, vector<Suit> costumes, double max_speed = 0){
    int best_plavka = best(plavki);
    int best_costume = best(costumes);
    if (speeds.empty()){
        cout << max_speed;
        return max_speed;
    }
    else {
        int current_speed = speeds[0];
        if (best_plavka == -1 && best_costume == -1)
            return max_speed + sum(speeds);
        else if (best_plavka == -1){
            max_speed += current_speed *  (1 + (best_costume / (double)100));
            costumes.erase(costumes.begin());
        }
        else if (best_costume == -1){
            max_speed += current_speed + best_plavka;
            plavki.erase(plavki.begin());
        }
        else {
            int choice_p = current_speed + best_plavka;
            int choice_c = current_speed * (1 + best_costume / (double)100);
            bool flag = (choice_p > choice_c ? true : false);
            if (flag){
                max_speed += choice_p;
                plavki.erase(plavki.begin());
            } else {
                max_speed += choice_c;
                costumes.erase(costumes.begin());
            }
        }
    }
    info(max_speed);
    ainfo(speeds);
    ainfo(plavki);
    ainfo(costumes);
    speeds.erase(speeds.begin());
    optimal_speed(speeds, plavki, costumes, max_speed);
}


int main(){
    //freopen("costumes.in", "r", stdin);
    //freopen("costumes.txt", "w", stdout);
    int swimmers = 0;
    cin >> swimmers;
    vector<int> speeds(swimmers);
    FOR(swimmers)
        cin >> speeds[i];

    int suits = 0;
    cin >> suits;
    vector<Suit> costumes;
    vector<Suit> plavki;
    FOR(suits) {
        int type = 0;
        int increase = 0;
        cin >> type >> increase;
        Suit suit = {type, increase};
        if (type == 1)
            costumes.push_back(suit);
        else
            plavki.push_back(suit);
    }


    // 1
    sort(speeds.begin(), speeds.end(), cmp1);
    sort(costumes.begin(), costumes.end(), cmp2);
    sort(plavki.begin(), plavki.end(), cmp2);


    cout << optimal_speed(speeds, plavki, costumes);



/*
    cout << "speed" << endl;
    FOR(swimmers)
        cout << speed[i] << ' ';

    cout << endl;

    cout << "costumes" << endl;
    FOR(cc)
        cout << costumes[i] << endl;

    cout << endl;

    cout << "plavki" << endl;
    FOR(cp)
        cout << plavki[i] << endl;
*/
}

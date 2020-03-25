#include <iostream>
#include <cmath>
#define Print(msg, value) cout << #msg << " = " << value << endl;

using std::cin;
using std::cout;
using std::endl;
using std::string;
using ull = unsigned long long;


string last = "That was last number";


//Long arithmetic Part 1
//Enumerate next ticket bigger for 1 then previous
string const& next_candidate(string& current){
    for (int remain = 1, i = current.size() - 1; i >= 0; i--){
        int value = current[i] - '0' + remain;
        if (value < 10){
            current[i] += remain;
            //Print(current, current);
            return current;
        } else {
            current[i] = (value % 10) + '0';
        }
    }
    return last;
}


//First ticket
string& make_zeros_string(short n, string& zeros){
    while (n--) zeros += "0";
    return zeros;
}


//Checking for lucky ticket condition about sum of numbers
bool left_equal_right(string& current){
    size_t len_of_side = current.size() / 2;
    ull sum_left_side = 0;
    ull sum_right_side = 0;
    for (size_t l = 0, r = current.size() - 1; l < len_of_side; ++l, --r){
        sum_left_side += current[l] - '0';
        sum_right_side += current[r] - '0';
    }
    return sum_left_side == sum_right_side;
}

//Filters lucky ticket
bool filter(string& current){
    if (left_equal_right(current))
        return true;
    return false;
}


void next_counter(string& counter){
    for (int remain = 1, i = counter.size() - 1; i >= -1; i--){
        if (i == -1){
            counter = "1" + counter;
            return;
        }
        int value = counter[i] - '0' + remain;
        if (value < 10){
            counter[i] += remain;
            //Print(counter, counter);
            return;
        } else {
            counter[i] = (value % 10) + '0';
        }
    }
}

//Evaluate result
void computing(string& current, string& counter){
    if (filter(current))
        next_counter(counter);
    if (next_candidate(current) == "That was last number"){
        cout << counter;
        return;
    }
    computing(current, counter);
}

int main(){
    std::ios::sync_with_stdio(false);
    short n = 0;
    cin >> n;
    string zeros;
    string counter = "0";
    //cout << make_zeros_string(n, zeros).size();
    computing(make_zeros_string(n, zeros), counter);
}

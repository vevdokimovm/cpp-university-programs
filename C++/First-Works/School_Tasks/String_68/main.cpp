#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    char last_seen_char = '#';
    int s_size = s.size();
    for (int i = 0; i < s_size; i++){
        if (s[i] >= 'a' && s[i] <= 'z'){
            if (s[i] <  last_seen_char){
                cout << i + 1;
                return 0;
            } else {
                 last_seen_char = s[i];
            }
        }
    }
    cout << 0;
}

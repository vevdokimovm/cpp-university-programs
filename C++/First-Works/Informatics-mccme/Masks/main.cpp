#include <iostream>

using namespace std;

int main()
{
    string mask = "";
    cin >> mask;
    string a[5] = {};
    for (size_t i = 0; i < 5; ++i)
        cin >> a[i];

    char previous = '\0';
    for (size_t i = 0; i < 5; ++i){
        for (size_t j = 0; j < mask.size(); ++j){
            if (mask[i] == a[i][j])
            else if (mask[i] == '?')
                if ()
            else if (mask[i] == '*'){
                while (mask[])
            }
    }
    return 0;
}

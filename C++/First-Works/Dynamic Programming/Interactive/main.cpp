#include <iostream>

using namespace std;

void binary_search_(){
    int left = 1;
    int right = 1000000;
    while (left != right){
        int mid = (left + right + 1) / 2;
        cout << mid << endl;

        char response[3];
        cin >> response;
        if (response[0] == '<')
            right = mid - 1;
        else
            left = mid;
    }
    cout << "! " << left << endl;
}

int main()
{
    binary_search_();
    return 0;
}

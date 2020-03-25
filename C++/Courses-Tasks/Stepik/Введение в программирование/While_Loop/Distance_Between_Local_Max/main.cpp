#include <iostream>

using namespace std;

int main()
{
    int dist = 0, c3 = 0, c2 = 0, c = 0, now, now1, now2;
    cin >> now >> now1 >> now2;
    while (now2 != 0){
        if (now1 > now && now1 > now2){

        now1 = now2;
        now = now1;
        cin >> now2;
    }
    cout << "Hello world!" << endl;
    return 0;
}

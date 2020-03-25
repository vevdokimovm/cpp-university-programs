#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    string ans;
    int boyz, girlz;
    cin >> boyz >> girlz;
    //Check - up for possibility
    if ((double)boyz / girlz > 2 || girlz / (double)boyz > 2){
        cout << "NO SOLUTION";
        exit(0);
    }
    if (boyz == girlz){
        for (int i = 0; i < n; i++){
            (i % 2 == 0) ? ans += 'B' : ans += 'G';
        }
    }
}

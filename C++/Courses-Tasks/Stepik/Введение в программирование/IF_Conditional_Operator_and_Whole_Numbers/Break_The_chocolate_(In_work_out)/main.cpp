#include <iostream>

using namespace std;

int main()
{
    setlocale (LC_ALL,"Russian");
    int n,m,k,r;
    cout << "Write down n m k " << endl;
    cin>> n >> m >> k;
    if ( ( ( ( (k==m*(r<n) || k==n*(r<m) ) && (r>0) ) && (n*m<30000)) && (k<m*n) )
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}

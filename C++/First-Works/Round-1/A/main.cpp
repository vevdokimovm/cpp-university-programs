#include <iostream>

using namespace std;

int main()
{
    int v1, v2, v3, v4;
    cin>>v1>>v2>>v3>>v4;
    if(v1>v4 && v2>v4){
        for(int i=v3;i<=2*v3;++i){
            if(i>=v4 && i<=2*v4){
                cout<<2*v1<<endl<<2*v2<<endl<<i;
                return 0;
            }
        }
    }
    cout<<-1;
}

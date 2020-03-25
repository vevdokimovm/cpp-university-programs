#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");
    int a,b,c,d,e,f;
    cout << "Write down c d a b" << endl;
    cin>>c>>d>>a>>b;
    if ((c>a) && (d>b))
    {
        e=c-a;
        f=d-b;
        cout<<e<<","<<f<<endl;
    }
    else if ((c>a) && (d<b))
    {
        e=(c-a)-1;
        f=(100+d)-b;
        cout<<e<<","<<f<<endl;
    }
    else if (c<a)
    {
        cout<<"Wrong data"<<endl;
    }
    else if ((c==a) && (d==b))
    {
        cout<<0<<","<<0<<endl;
    }
    return 0;
}

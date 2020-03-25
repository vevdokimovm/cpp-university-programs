#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int x, y, term;
    term=0;
    cout <<"Write down   x y"<<endl;
    cin >> x >> y;
    if ((x > 0) && (y > 0))
    {
        term = 1;
        cout << term << endl;
    }
    else if ((x < 0) && (y < 0))
    {
        term = 4;
        cout << term << endl;
    }
    else if ((x < 0) && (y > 0))
    {
        term = 2;
        cout << term << endl;
    }
    else if ((x > 0) && (y < 0))
    {
        term = 3;
        cout << term << endl;
    }
    else if ((x==0) && (y==0))
    {
        cout<<"Wrong data"<<endl;
    }
     else if ((x==0) && (y>0))
    {
        cout<<"Wrong data"<<endl;
    }
     else if ((x==0) && (y<0))
    {
        cout<<"Wrong data"<<endl;
    }
     else if ((x<0) && (y==0))
    {
        cout<<"Wrong data"<<endl;
    }
     else if ((x>0) && (y==0))
    {
        cout<<"Wrong data"<<endl;
    }
    return 0;
    }


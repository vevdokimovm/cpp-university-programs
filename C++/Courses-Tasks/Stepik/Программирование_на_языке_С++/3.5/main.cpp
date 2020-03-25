#include <iostream>

using namespace std;

struct Cls_{
    char k;
    double d;
    int i;

};

struct Cls {
    Cls(char c, double d, int i)
        : c(c), d(d), i(i) {}
    int get_i1() {return i;}
    double get_d1() {return d;}
    char get_c1() {return c;}
private:
    char c;
    double d;
    int i;
};

char & get_c(Cls &cls){
     return ((Cls_ *)(&cls))->k;
}


double & get_d(Cls &cls){
     return *(double *)((char *)&cls + 8);
}

int & get_i(Cls &cls) {
     return *(int *)((char *)&cls + 16);
}

int main()
{
    char c = 'g';
    double d = 8.86;
    int i = 6;
    Cls cls1(c, d, i);
    get_c(cls1) = 'j';
    get_d(cls1) = 56.34;
    get_i(cls1) = 745;
    cout << cls1.get_c1() << " " << cls1.get_d1() << " " << cls1.get_i1() << " " << sizeof(cls1);
    return 0;
}

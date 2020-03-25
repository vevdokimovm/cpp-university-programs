#include <iostream>

using namespace std;

struct String
{
    String(size_t n, char c)
    {
        size_ = n;
        str = new char [size_ + 1];
        for (size_t i = 0; i < n; ++i)
            str[i] = c;
        str[n] = '\0';
    }
    ~String(){
        delete [] str;
    }
    size_t size_;
    char * str;
};

int main()
{
    size_t h = 5;
    char p = 'p';
    String str(h, p);
    for (size_t i = 0; i < str.size_; ++i)
        cout << str.str[i] << " ";
}

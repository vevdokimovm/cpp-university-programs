#include <iostream>

using namespace std;

char *resize_fun(const char *str, unsigned size, unsigned new_size)
{
	char * a = new char [new_size];
	for (size_t i = 0; i < min(size, new_size); ++i)
    {
        a[i] = str[i];
    }
    delete [] str;
    str = 0;
    return a;
}



int main()
{
    char * a = new char [10];
    for (size_t i = 0; i < 10; ++i)
    {
        cin >> a[i];
    }
    char * ptr = resize_fun(a, 10, 11);
    for (size_t i = 0; i < 11; ++i)
    {
        cout << ptr[i] << " ";
    }
    cout << a[4];
}

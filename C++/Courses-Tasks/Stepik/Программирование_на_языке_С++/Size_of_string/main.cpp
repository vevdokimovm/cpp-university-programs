#include <iostream>

using namespace std;

unsigned strlen( char* str)
{
    unsigned str_size = 0;
    for (; *str != '\0'; str++)
        str_size++;
    return str_size;
}

int main()
{
    char a[500] = "abcdkg";
    int f = 0;
    char * ptr = a;
    while(*ptr++) {++f;}
    cout << *ptr << " " << f;
    return 0;
}

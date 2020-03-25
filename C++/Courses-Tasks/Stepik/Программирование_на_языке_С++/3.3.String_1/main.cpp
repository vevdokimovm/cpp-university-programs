#include <iostream>
#include <cstring>
#include <cstddef>

using namespace std;

struct String
{
    String(const char *str = "")
        : size_(strlen(str)), str(strcpy(new char [strlen(str)], str)) {}
    size_t size_;
    char *str;
};

int main(){
    char str1 [] = "777";
    String str2(str1);
    cout << str2.size_ << " " << strlen(str1) << endl;
    for (size_t i = 0; i < strlen(str1); ++i)
        cout << str1[i] << " ";
}

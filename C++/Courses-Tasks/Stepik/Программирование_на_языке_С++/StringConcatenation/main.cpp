#include <iostream>

using namespace std;

void strcat1(char * to, const char * from)
{
    for (; *to != '\0'; to++){};
    for (; *from != '\0'; from++, to++)
    {
        *to = *from;
    }
    *to = '\0';
}

int main()
{
    char str1[100] = "Vasya ";
    const char str2[] = "pretty boy";
    strcat1(str1, str2);
    cout << str1;
    return 0;
}

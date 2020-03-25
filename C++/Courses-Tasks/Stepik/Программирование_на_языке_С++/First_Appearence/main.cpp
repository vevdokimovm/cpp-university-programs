#include <iostream>

using namespace std;

int strstr(const char *text, const char *pattern)
{
    int pattern_size = 0;
    for (; *pattern != 0; ++pattern)
        pattern_size++;
    if (pattern_size == 0)
        return 0;
    int str1_size = 0;
    for (; *text != '\0'; ++text)
        str1_size++;
    text -= str1_size;
    pattern -= pattern_size;
    int counter = 0;
    for (int i = -1; i < (str1_size - 1); ++i)
    {
        for (int j = i + 1; j < str1_size; ++j)
        {
            if (text[j] == pattern[counter])
            {
                counter++;
                if (counter == pattern_size)
                    return i + 1;
            } else {
                counter = 0;
                break;
            }
        }
    }
    return -1;
}

int main()
{
    const char str1[] = "Vat";
    const char str2[] = "Vas";
    cout << strstr(str1, str2) << endl;
    return 0;
}

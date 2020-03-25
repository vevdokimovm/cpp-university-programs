#include <cstddef> // size_t
#include <cstring>
#include <iostream>

struct String {
	String(const char *str = "")
        : size_s(strlen(str)), str(strcpy(new char [size_s + 1], str)) {}
	String(size_t n, char c);
	//~String();

    String(const String &other);
    String &operator=(const String &other);

    struct SubString {
        SubString(const char * str = "", size_t i = 0)
            : size_sub(strlen(str)), str_sub(strcpy(new char [size_sub + 1], str)), i(i) {}
        ~SubString () { delete [] str_sub; }
        String operator[](size_t j) const{
            char* temp_str = new char [j - i + 1];
            for (size_t k = 0; k < j - i; ++k)
                temp_str[k] = str_sub[k];
            temp_str[j - i] = '\0';
            String temp(temp_str);
            delete [] temp_str;
            return temp;
        }
        size_t size_sub;
        char* str_sub;
        size_t i;
    };

    SubString operator[] (size_t i) const{
        return SubString(str + i, i);
    }

	void append(const String &other);

	size_t size_s;
	char *str;
};

int main()
{
    String const hello("hello");
    String const ell  = hello[1][2];
    for (size_t i = 0; i < strlen(ell.str) ; ++i)
        std::cout << ell.str[i];
    std::cout << " " << ell.size_s<< " ";

}

#include <iostream>
#include <cstring>

using namespace std;

struct String {
    String(const char *str = "")
        : size_(strlen(str)), str(strcpy(new char [strlen(str)], str)) {}
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
    /* Реализуйте этот метод. */
	void append(String & other){
	    char * new_ptr = new char [size_ + other.size_ + 1];
	    strcpy(new_ptr, str);
	    strcpy(new_ptr + size_, other.str);
        delete [] str;
        str = new_ptr;
        size_ += other.size_;
	}

	size_t size_;
	char *str;
};
int main()
{
    size_t a = 5, b = 6;
    char f = 'f', g = 'g';
    String s1(a, f), s2(b, g);
    s1.append(s1);
    for (size_t i = 0; i < a + b + 1; ++i)
        cout << s1.str[i];
    cout << s1.size_ << endl;
    for (size_t i = 0; i <  b; ++i)
        cout << s2.str[i];
}

#include <algorithm> // std::swap
#include <cstddef>   // size_t
#include <cstring>   // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	String(const String &other);
	~String();

	void swap(String & a){
        std::swap(a.size, size);
        stt::swap(a.str, str);
	}

    /* Реализуйте оператор присваивания */
	String &operator=(const String &other){
        String(other.str).swap(*this);
        return *this;
    }

	void append(const String &other);

	size_t size;
	char *str;
};

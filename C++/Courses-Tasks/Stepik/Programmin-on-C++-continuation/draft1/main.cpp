#include <iostream>
#include <typeinfo>

struct String{
    void swap_(String & temp){
        std::swap(data_, temp.data_);
        std::swap(size_, temp.size_);
    }

    String() = default;
    String(String && s){
        swap_(s);
    }
    String & operator = (String && s){
        swap_(s);
        return *this;
    }

    char * data_ = nullptr;
private:
    size_t size_ = 0;
};

int main()
{
    String s;
    s.data_ = "Hello world";
    String i;
    i = s;
}

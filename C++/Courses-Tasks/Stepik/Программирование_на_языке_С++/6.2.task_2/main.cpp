#include <iostream>
#include <cstddef>
template <typename T>
class Array
{
public:
    explicit Array(size_t size = 0, const T& value = (const T)0)
        : size_(size), ptr_((T*)new char[size_ * sizeof(T)])
        {
            for (size_t i = 0; i < size_; ++i)
                new (ptr_ + i) T(value);
        }
    Array(const Array & Arr)
        : size_(Arr.size_), ptr_((T*)new char[size_ * sizeof(T)])
        {
            for (size_t i = 0; i < size_; ++i)
                new (ptr_ + i) T(Arr.ptr_[i]);
        }
    ~Array() {
        for (size_t i = 0; i < size_; ++i)
            ptr_[i].~T();
        delete [] (char*)ptr_;
    }
    void swapper(Array & Arr){
        std::swap(ptr_, Arr.ptr_);
        std::swap(size_, Arr.size_);
    }
    Array& operator=(const Array & Arr){
        Array(Arr).swapper(*this);
        return *this;
    }

    size_t size() const { return size_; }

    T& operator[](size_t i) { return ptr_[i]; }
    const T& operator[](size_t i) const { return ptr_[i]; }

private:
    size_t size_;
    T* ptr_;
};

bool less(int a, int b) { return a < b; }
struct Greater { bool operator()(int a, int b) const { return b < a; } };

template<typename Type,
         typename Cmp>
Type minimum(Array<Type> & object, Cmp fun){
    Type temp = object[0];
    for (size_t i = 0; i < object.size(); ++i)
        fun(temp, object[i]) ? temp : temp = object[i];
    return temp;
}

int main(){
    Array<int> ints(3);
    ints[0] = 10;
    ints[1] = 2;
    ints[2] = 15;
    int min_ = minimum(ints, less);
    int max_ = minimum(ints, Greater());
    std::cout << min_ << ' ' << max_;
}

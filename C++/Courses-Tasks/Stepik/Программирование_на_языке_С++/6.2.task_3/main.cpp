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


template<typename T>
void flatten(const Array<T>& object, std::ostream& out){
    for (size_t i = 0; i < object.size(); ++i)
        out << object[i] << ' ';
}

template <typename T>
void flatten(const Array<Array<T>>& arr, std::ostream& out){
    for (size_t i = 0; i < arr.size(); ++i)
        flatten(arr[i], out);
}


int main(){
    Array<int> ints(2, 0);
    ints[0] = 10;
    ints[1] = 20;
    flatten(ints, std::cout); // выводит на экран строку "10 20"
    Array< Array<int> > array_of_ints(2, ints);
    flatten(array_of_ints, std::cout); // выводит на экран строку "10 20 10 20"
    Array<double> doubles(10, 0.0);
    flatten(doubles, std::cout);
}

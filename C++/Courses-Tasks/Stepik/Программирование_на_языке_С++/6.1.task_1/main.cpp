#include <cstddef>
template <typename T>

class Array
{
public:
    explicit Array(size_t size = 0, const T& value = T())
        : size_(size), ptr_(new T[size_])
        {
            for (size_t i = 0; i < size_; ++i)
                ptr_[i] = value;
        }
    Array(const Array & Arr)
        : size_(Arr.size_), ptr_(new T [size_])
        {
            for (size_t i = 0; i < size_; ++i)
                ptr_[i] = Arr.ptr_[i];
        }
    ~Array() { delete [] ptr_; }

    void swapper(Array & Arr){
        std::swap(size_, Arr.size_);
        std::swap(ptr_, Arr.ptr_);
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
int main()
{
    const Array<int> g(10, 5);
    std::cout << g[3];
}

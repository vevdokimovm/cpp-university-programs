#include <iostream>
#include <cstddef>

//struct Expression;
//struct Number;
//struct BinaryOperation;

struct SharedPtr
{
    explicit SharedPtr(int *ptr = 0)
        : _ptr(ptr), _counter(0) { if (_ptr) _counter = new size_t(1); }
    ~SharedPtr(){
        if (_ptr && --*_counter == 0)
            delete _ptr, delete _counter;
    }
    SharedPtr(const SharedPtr & sharedptr)
        : _ptr(sharedptr._ptr), _counter(sharedptr._counter) { if (_ptr) ++*_counter; }
    void swapper(SharedPtr & sharedptr){
        std::swap(_ptr, sharedptr._ptr);
        std::swap(_counter, sharedptr._counter);
    }
    SharedPtr& operator=(const SharedPtr & sharedptr){
        if (_ptr && --*_counter == 0) delete _ptr, delete _counter;
        if (sharedptr._ptr) ++*sharedptr._counter;
        SharedPtr(sharedptr).swapper(*this);
        return *this;
    }


    int* get() const { return _ptr; }
    void reset(int *ptr = 0){
        if (_ptr && --*_counter == 0) delete _ptr, delete _counter;
        _ptr = ptr;
        _counter = new size_t(1);
    }
    int& operator*() const { return *_ptr; }
    int* operator->() const { return _ptr; }
    int* _ptr;
    size_t* _counter;
};


int main()
{
    int lel = 89;
    SharedPtr ptr(&lel);
    SharedPtr kek = ptr;
    SharedPtr ptr1(&lel);
    ptr = ptr;
    int i = 45;
    kek.reset(&i);
    ptr.reset(&i);
    ptr1.reset(&i);
    //std::cout << *i;
    int a[5] = {};
    int* p = 0;
    std::cout << sizeof(a) << " " << sizeof(p);
    return 0;
}

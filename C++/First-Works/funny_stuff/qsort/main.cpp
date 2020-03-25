#include <iostream>
#include <cstdlib>

qsort

template<class T>
T* concatenation(T* less_members, T pivot, T* greater_members, size_t size_lesser, size_t size_greater){
    T new_array[size_lesser + 1 + size_greater] = {};
    for (size_t i = 0; i < size_lesser; ++i)    new_array[i] = less_members[i];
    new_array[size_lesser] = pivot;
    for (size_t i = size_lesser; i < size_greater + size_greater; ++i)  new_array[i] = greater_members[i];
    return new_array;

}

template<class T, size_t S>
T* qsort(T (&s)[S]){
    if (S < 2) return s;
    else {
        T pivot = s[0];
        size_t less_counter = 0;
        size_t greater_counter = 0;
        for (size_t i = 0; i != S; ++i)
            s[i] < pivot ? ++less_counter : ++greater_counter;
        T less_members[less_counter] = {};
        T greater_members[greater_counter] = {};
        for (size_t i = 0; i != S; ++i)
            s[i] < pivot ? less_members[--less_counter] : greater_members[--greater_counter];
        return concatenation(qsort(less_members), pivot, qsort(greater_members), S, less_counter, greater_counter);
    }
}

int main()
{
    int a[] = {5, 4, 3, 2, 1};
    qsort(a);
    for (size_t i = 0; i < 5; ++i) std::cout << a[i];
    return 0;
}

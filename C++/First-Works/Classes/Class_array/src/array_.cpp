#include "array_.h"
#include <iostream>
#include <cmath>

using namespace std;

    void array_::initilization(int b, int i){
        a[i] = b;
    }
    int array_::length(){
        return n;
    }
    void array_::output(){
        cout << "Your array " << name << " = ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
    int array_::max(){
        int ans = a[0];
        for (int i = 1; i < n; i++){
            if (ans < a[i]){
                ans = a[i];
            }
        }
        return ans;
    }
    int array_::min(){
        int ans = a[0];
        for (int i = 1; i < n; i++){
            if (ans > a[i]){
                ans = a[i];
            }
        }
        return ans;
    }
    void array_::choice_sort(){
        int smallest, smallest_index = 0;
        for (int i = 0; i < n; i++){
            smallest = a[i];
            for (int j = i + 1; j < n; j++){
                if (smallest >= a[j]){
                    smallest = a[j];
                    smallest_index = j;
                }
            }
            if (smallest_index >= i)
                swap(a[i], a[smallest_index]);
            smallest_index = 0;
        }
        cout << "Sorted = ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
    void array_::reverse_()
    {
        int swapper = n - 1;
        int middle_index = n / 2;
        floor(middle_index);
        for (int i = 0; i <= middle_index - 1; i++){
            swap(a[i], a[swapper]);
            swapper--;
        }
        cout << endl << "Reversed = ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }

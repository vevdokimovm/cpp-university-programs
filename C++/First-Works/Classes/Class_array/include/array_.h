#pragma once
#include <string>
#include <iostream>

using namespace std;

class array_
{
private :
    int* a;
    int n;
    string name;
public :
     array_(int b, string s){
        n = b;
        a = new int[n];
        name = s;
    }
    void initilization(int, int);
    int length();
    int max();
    int min();
    void choice_sort();
    void output();
    void reverse_ ();
};

 // ARRAY__H

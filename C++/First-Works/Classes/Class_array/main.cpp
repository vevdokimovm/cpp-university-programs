#include <iostream>
#include <cmath>
#include <array_.h>

int main()
{
    int n;
    string name;
    cin >> n >> name;
    array_ a(n, name);
    for (int i = 0; i < a.length(); i++){
        int element;
        cin >> element;
        a.initilization(element, i);
    }
    a.output();
    cout << endl << "Max element = " << a.max() << endl << "Min element = " << a.min() << endl;
    a.choice_sort();
    a.reverse_();
    return 0;
}

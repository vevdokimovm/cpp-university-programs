#include <iostream>
#include <algorithm>
#define INFO(msg) std::cout << #msg << " = " << msg << std::endl;
#define LOG(c) std::cout << "Entered : " << c << std::endl;
typedef long long ll;
typedef unsigned long long ull;

struct Point{
    Point()
        : x(0), y(0), z(0) {}
    ll x;
    ll y;
    ll z;
};

bool belong_to_line(Point base1, Point base2, Point temp){
    return (((base2.x - base1.x) / (double)(temp.x - base1.x)) == ((base2.y - base1.y) / (double)(temp.x - base1.y)) &&
            ((base2.z - base1.z) / (double)(temp.z - base1.z)) == ((base2.y - base1.y) / (double)(temp.x - base1.y)));
}

void make_equation(Point a[], ull elements_a, ull arr_queue[], ull element, ull& dot1In, ull& dot2In){
    arr_queue[element] = 2;
    for (size_t i = 0; i < elements_a; ++i)
        if (i != dot1In && i != dot2In)
            if (belong_to_line(a[dot1In], a[dot2In], a[i]))
                ++arr_queue[element];
}

bool have_more_than_three(ull a[], ull elements){
    ull counter = 0;
    for(size_t i = 0; i < elements; ++i)
        if (a[i] < 3){
            a[i] = (ull)-1;
            ++counter;
        }
    return (counter == elements);
}

int main()
{
    std::ios::sync_with_stdio(0);
    ull number_of_coords = 0;
    std::cin >> number_of_coords;
    Point a[number_of_coords];
    for (size_t i = 0; i < number_of_coords; ++i){
        std::cin >> a[i].x >> a[i].y >> a[i].z;
    }

    ull elements = (number_of_coords - 1) * (number_of_coords / 2);
    ull array_lenght_line[elements] = {};
    ull counter1 = 0;
    ull counter2 = 0;
    ull i = 0;
    while (elements--){
        make_equation(a, number_of_coords, array_lenght_line, i++, counter1, counter2);
    }

    bool flag = have_more_than_three(array_lenght_line, number_of_coords);

    if (flag)
        std::cout << 0;
    else {
        ull* answer = std::min_element(array_lenght_line, array_lenght_line + elements);
        std::cout << *answer;
    }

    std::cout << std::endl;
    for (size_t i = 0; i < elements; ++i)
        std::cout << array_lenght_line[i] << ' ';
    return 0;
}

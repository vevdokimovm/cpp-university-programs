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

bool belong_to_line(Point temp, Point base){
    return (((temp.x - base.x) / (double)base.x) == ((temp.y - base.y) / (double)base.y) && ((temp.y - base.y) / (double)base.y) == ((temp.z - base.z) / (double)base.z) &&
                                                                                            ((temp.z - base.z) / (double)base.z) == ((temp.x - base.x) / (double)base.x));
}

void make_equation(Point a[], ull elements, ull arr_queue[], ull& cur_element_index){
    for (size_t i = 0; i < elements; ++i)
        if (belong_to_line(a[i], a[cur_element_index])){
            ++arr_queue[cur_element_index];
        }
    ++cur_element_index;
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


    ull array_lenght_line[number_of_coords] = {};
    ull counter = 0;
    while (counter < number_of_coords){
        make_equation(a, number_of_coords, array_lenght_line, counter);
    }

    bool flag = have_more_than_three(array_lenght_line, number_of_coords);

    if (flag)
        std::cout << 0;
    else {
        ull* answer = std::min_element(array_lenght_line, array_lenght_line + number_of_coords);
        std::cout << *answer;
    }

    //std::cout << std::endl;
    //for (size_t i = 0; i < number_of_coords; ++i)
    //    std::cout << array_lenght_line[i] << ' ';
    return 0;
}

#include <iostream>
#include <algorithm>
#define INFO(msg) std::cout << #msg << " = " << msg << std::endl;
#define LOG(c) std::cout << "Entered : " << c << std::endl;
typedef long long ll;

bool cmp(ll a, ll b){
    return (a < b);
}

ll* first_left(ll limit, ll a[], ll& start_index, ll elements){
    while (start_index < elements && a[++start_index] <= limit){}
    --start_index;
    return (a + start_index);
}

int main(){
    std::ios::sync_with_stdio(false);
    ll number_of_coordinates = 0;
    ll max_distance = 0;
    std::cin >> number_of_coordinates >> max_distance;
    ll array_of_coords[number_of_coordinates] = {};


    for (size_t i = 0; i < number_of_coordinates; ++i)
        std::cin >> array_of_coords[i];


    if (number_of_coordinates < 2){ std::cout << 1; return 0; }


    std::sort(array_of_coords, array_of_coords + number_of_coordinates, cmp);


    ll pi_index = 0;
    ll* pivot = first_left(array_of_coords[0] + max_distance, array_of_coords, --pi_index, number_of_coordinates);
    ll counter = 1;


    if (pivot == (array_of_coords + number_of_coordinates - 2)){ //Pre-last element
        if (*pivot + max_distance >= array_of_coords[number_of_coordinates - 1]){
            std::cout << counter;
            return 0;
        }else { std::cout << ++counter; return 0; }
    } else {
        for (ll i = pi_index; *pivot + max_distance < array_of_coords[number_of_coordinates - 1];){
            ll prev_i = i;
            pivot = first_left(*pivot + 2 * max_distance + 1, array_of_coords, --i, number_of_coordinates);
            if (prev_i == i) { ++i; pivot = (array_of_coords + i); } //New pivot
            counter += 1;
        }
    }

    std::cout << counter;
    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;

struct Coord{
    Coord()
        : x(0), y(0) {}
    ull x;
    ull y;
};

struct Travel{
    Travel()
        : x1(0), y1(0), x2(0), y2(0) {}
    ull x1;
    ull y1;
    ull x2;
    ull y2;
};

ull overall_timing(std::vector<std::vector<ull>> time, Coord begining[], Travel travel[], size_t j){
    return (std::abs(begining[j].x - travel[j].x1) + std::abs(begining[j].y - travel[j].y1) +
            std::abs(travel[j].x2 - travel[j].x1) + std::abs(travel[j].y2 - travel[j].y1));
}

void fullfilment(std::vector<std::vector<ull>> time, Coord begining[], Travel travel[], ull overall_time[]){
    for (size_t i = 0; i < time.size(); ++i){
        for (size_t j = 0; j < time.size(); ++j){
            overall_time[i * time.size() + j] = overall_timing(time, begining, travel, j);
        }
    }
}

int main()
{
    short n = 0;
    std::cin >> n;


    Coord begining[n] = {};
    for (size_t i = 0; i < static_cast<ull>(n); ++i)
        std::cin >> begining[i].x >> begining[i].y;


    Travel travel[n] = {};
    for (size_t i = 0; i < static_cast<ull>(n); ++i)
        std::cin >> travel[i].x1 >> travel[i].y1 >> travel[i].x2 >> travel[i].y2;


    std::vector<std::vector<ull>> time(n);

    ull overall_time[n * n] = {};
    fullfilment(time, begining, travel, overall_time);

    for (size_t i = 0; i < static_cast<size_t>(n * n); ++i)
        std::cout << overall_time[i] << " ";
    return 0;
}

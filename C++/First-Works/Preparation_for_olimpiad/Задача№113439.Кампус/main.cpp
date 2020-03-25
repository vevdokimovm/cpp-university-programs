#include <iostream>

using namespace std;

int main()
{
    long long n, k, floor_rooms_k, floor_rooms_rest, count_flats;
    cin >> n >> k >> floor_rooms_k >> floor_rooms_rest >> count_flats;
    for (int i = 0; i < count_flats; i++){
        long long room_num;
        cin >> room_num;
    }
    long long rooms_in_entrance, rooms_k, rooms_rest;
    rooms_k = (n / k) * floor_rooms_k;
    rooms_rest = (n - n / k) * floor_rooms_rest;
    rooms_in_entrance = rooms_k + rooms_rest;
    cout << rooms_in_entrance;
    return 0;
}

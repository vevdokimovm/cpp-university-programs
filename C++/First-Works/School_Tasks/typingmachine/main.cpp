#include <iostream>
#define DEBUG(str) std::cout << #str << " = " << str << "\n";

int main(){
    std::ios::sync_with_stdio(0);
    std::string x;
    std::string z;
    std::cin >> x >> z;
    typedef long long ll;
    ll pos_z_in_x = x.find(z);
    ll pos_x_in_z = z.find(x);
    //Answer - nothing
    if (pos_z_in_x != std::string::npos && pos_z_in_x + z.size() == x.size()) { std::cout << ""; return 0; }
    else if (pos_x_in_z == 0){
        ll pos = -1;
        while (pos < (ll)(z.size() - 1) && (pos = z.find(x, ++pos)) != std::string::npos) {}
        if (pos + x.size() == z.size()) { std::cout << ""; return 0; }
    }
    //Answer - z
    if ((pos_z_in_x == std::string::npos && (pos_x_in_z != 0 || pos_x_in_z != std::string::npos)) || pos_z_in_x + z.size() != x.size()){ std::cout << z; return 0; }
    return 0;
    //Answer - letters
    ll n = z.size() / x.size() + 1;
    std::string n_x;
    for (size_t i = 0; i < n; ++i)
        n_x += x;
    std::cout << n_x;
}

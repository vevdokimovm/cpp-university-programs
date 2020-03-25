#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    unsigned n = 0, counter = 0;
    std::string a = "", b = "";
    std::cin >> n >> a >> b;
    for (size_t i = 0; i < n - 1; ++i)
        for (size_t j = i + 1; j < n; ++j){
            if ((a[i] == '1' && a[j] == '1') || (a[i] == '0' && a[j] == '0')) continue;//case 1 or case 3
            else if (!(a[i] == '1' && a[j] == '0' && b[i] == '1' && b[j] == '1') && !(a[i] == '0' && a[j] == '1' && b[i] == '1' && b[j] == '1'))//case 2
                ++counter;
            else if (!(a[i] == '0' && a[j] == '1' && b[i] == '1' && b[j] == '1') && !(a[i] == '1' && a[j] == '0' && b[i] == '1' && b[j] == '1'))//case 4
                ++counter;
        }
    std::cout << counter;
    return 0;
}

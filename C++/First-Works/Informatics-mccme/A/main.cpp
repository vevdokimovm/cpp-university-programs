#include <iostream>

using namespace std;

using ull = unsigned long long;

struct Place {
    ull tr_start;
    ull fl_start;
    ull tr_finish;
    ull fl_finish;
};

int main()
{
    ios::sync_with_stdio(false);
    ull towers = 0;
    ull flats = 0;
    ull min_flat = 0;
    ull max_flat = 0;
    ull destinations = 0;
    cin >> towers >> flats >> min_flat >> max_flat >> destinations;

    Place a[destinations];
    for (size_t i = 0; i < destinations; ++i)
        cin >> a[i].tr_start >> a[i].fl_start >> a[i].tr_finish >> a[i].fl_finish;

    for (size_t k = 0; k < destinations; ++k){
        ull timer = 0;
        while ((a[k].tr_start != a[k].tr_finish) || (a[k].fl_start != a[k].fl_finish)){
            if (a[k].tr_start != a[k].tr_finish)
                if (a[k].fl_start >= min_flat && a[k].fl_start <= max_flat)
                    if (a[k].tr_start < a[k].tr_finish)
                        ++a[k].tr_start;
                    else
                        --a[k].tr_start;
                else
                    if (a[k].fl_start > max_flat)
                        --a[k].fl_start;
                    else
                        ++a[k].fl_start;
            else
                if (a[k].fl_start < a[k].fl_finish)
                    ++a[k].fl_start;
                else
                    --a[k].fl_start;
            ++timer;
        }
        cout << timer << '\n';
    }

    //for (size_t i = 0; i < destinations; ++i)
     //   cout << a[i].tr_start << " " << a[i].fl_start << " " << a[i].tr_finish << " " << a[i].fl_finish << endl;

    return 0;
}

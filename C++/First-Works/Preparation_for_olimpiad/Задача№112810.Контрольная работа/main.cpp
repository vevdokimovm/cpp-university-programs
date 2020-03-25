#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>

using namespace std;

struct infostud{
    long long desk;
    long long row;
    long long variant;
};

int main()
{
    long long count_stud, count_variants, desk_peter, right_left_peter;
    cin >> count_stud >> count_variants >> desk_peter >> right_left_peter;
    long long row_t = 0, count_desk = 1, variant = 1;
    vector <infostud> a(count_stud);
    for (long long i = 0; i < a.size(); i++){
        infostud struct_temp;
        if (row_t % 2 == 0){
            row_t++;
            struct_temp.desk = count_desk;
            struct_temp.row = row_t % 2;
            struct_temp.variant = variant;
            variant %= count_variants;
            variant++;
        } else {
            row_t++;
            struct_temp.desk = count_desk;
            struct_temp.row = row_t % 2 + 2;
            struct_temp.variant = variant;
            variant %= count_variants;
            variant++;
            count_desk++;
        }
        a[i] = struct_temp;
    }
    for (auto now : a){
        cout << now.desk << " " << now.row << " " << now.variant << endl;
    }
    long long variant_peter = (desk_peter * 2 - right_left_peter % 2) % count_variants;
    if (variant_peter == 0){
        variant_peter = count_variants;
    }
    for (long long i = 0; i < a.size(); i++){
        if (a[i].variant == variant_peter && a[i].desk == desk_peter && a[i].row == right_left_peter){
            for (long long j = i + 1; j < a.size(); j++){
                if (a[j].variant == variant_peter){
                    cout << a[j].desk << " " << a[j].row;
                    exit(0);
                }
            }
            for (long long k = i - 1; k > 0; k--){
                if (a[k].variant == variant_peter){
                    cout << a[k].desk << " " << a[k].row;
                    exit(0);
                }
            }
            break;
        }
    }
    cout << -1;
    return 0;
}

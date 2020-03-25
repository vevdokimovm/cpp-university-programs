#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>

using namespace std;


int main()
{
    //freopen("C:\\Users\\Home\\Desktop\\input.txt", "r", stdin);
    //freopen("c:\\Users\\Home\\Desktop\\output.txt", "w", stdout);
    ifstream fin    ("c:\\users\\home\\desktop\\input.txt");
    ofstream fout    ("c:\\users\\home\\desktop\\output.txt", ios_base::app);
    //FILE * fin = fopen("input.txt", "r");
    //FILE * fout = fopen("output.txt", "at");
    int k, n, l;
    l = fin.is_open();
    //fscanf(fin, "%d%i", &k, &n);
    fin >> k >> n;
    vector <unsigned long long> a(n);
    int last = a.size() - 1;
    // Элементы достигаемые с начала
    for (int i = 0; i < k; i++){
            for (int j = 0; j < i; j++){
               a[i] += a[j];
            }
        a[i]++;
    }
    // Заполнение больше макс прыжка
    for (int i = k; i <= last; i++){
        for (int j = k; j > 0; j--){
            a[i] += a[i - j];
        }
    }
   // fprintf(fout, "%llu", a[last]);
    //fclose(fin);
    //fclose(fout);
    fout << a[last] << l;
    fin.close();
    fout.close();
    return 0;
}

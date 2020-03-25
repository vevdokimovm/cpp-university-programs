#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>

/* ¬ыведите все исходные точки в пор€дке возрастани€ их рассто€ний от начала координат.

¬ходные данные

ѕрограмма получает на вход набор точек на плоскости. —начала задано количество точек n, затем идет последовательность из n строк, кажда€ из которых содержит два числа: координаты точки. ¬еличина n не превосходит 100, все исходные координаты Ц целые числа, не превосход€щие 103.

¬ыходные данные

Ќеобходимо вывести все исходные точки в пор€дке возрастани€ их рассто€ний от начала координат.

Sample Input:
2
1 2
2 3
Sample Output:
1 2
2 3
*/

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return sqrt(pow(a.first, 2) + pow(a.second, 2)) < sqrt(pow(b.first, 2) + pow(b.second, 2));
}

int main()
{
    int n;
    cin >> n;
    vector<pair <int, int>> a(n);
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    sort(a.begin(), a.end(), comp);
    for (auto now : a){
        cout << now.first << " " << now.second << "\n";
    }
    return 0;
}

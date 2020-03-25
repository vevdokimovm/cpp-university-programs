#include <iostream>

using namespace std;

/*Дано натуральное число N. Выведите слово YES, если число N является точной степенью двойки, или слово NO в противном случае.
Формат входных данных
Вводится натуральное число.
Формат выходных данных
Выведите ответ на задачу.
Sample Input 1:
1
Sample Output 1:
YES
Sample Input 2:
2
Sample Output 2:
YES
*/

int main()
{
  int N,n=1;
  cin >> N;
  while (n*2<=N)
  {
      n = n*2;
  }
  if (N%n==0)
  {
     cout << "YES" << endl;
  }
  else
  {
      cout << "NO" << endl;
  }
  return 0;
}

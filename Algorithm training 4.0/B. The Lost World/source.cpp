#include <iostream>
#include <vector>

using namespace std;

int num_permutations = 0;
vector<bool> col, diag1, diag2;

void search(int y, int n) 
{
   if (y == n) 
   {
      num_permutations++;
      return;
   }
   for (int x = 0; x < n; x++) 
   {
      if (col[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
      col[x] = diag1[x + y] = diag2[x - y + n - 1] = true;
      search(y + 1, n);
      col[x] = diag1[x + y] = diag2[x - y + n - 1] = false;
   }
}

int main() 
{
   int n;
   cin >> n;
   col = vector<bool>(n);  
   diag1 = diag2 = vector<bool>(2 * n - 1);
   search(0, n);
   cout << num_permutations << endl;
   return 0;
}

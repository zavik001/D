#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int minB(vector<vector<int>> A, vector<pair<int, int>> K,int j)
{
   int n = K.size(), min = 0;

   for (int i = 0; i < n; i++)
   {
      int y = K[i].second;
      int p = abs(j - y) - 1;

      if (K[i].second != j && p != 0)
      {
         min += p;
         A[K[i].first][K[i].second] = 0;
         int offset = (K[i].second > j) ? -p : p;
         K[i] = {K[i].first, K[i].second + offset};
         A[K[i].first][K[i].second]++;
      }
   }

   
   for (int i = 0; i < n; i++)
   {
      int k = (j == 0 ? A[i][j+1] : (j == n-1 ? A[i][j-1] : A[i][j-1] + A[i][j+1]));
      cout << endl << "k =  " << k << endl;
      for (int q = k; q > 0; q--)
      {
         for (int s = 0; s < n; s++)
         {
            if (A[s][j] == 0)
            {
               A[s][j] = -1;
               min += abs(s - i) + 1;
               break;
            }
         }
      }
   }

   cout << endl;
   for (int i = 0; i < n; i++)
   {
      for (int k = 0; k < n; k++)
         cout << A[i][k] << " ";
      cout << endl;
   }
   cout << min << endl << endl << endl;

   return min;
}

int main ()
{
   int n = 0;
   cin >> n;
   vector<vector<int>> A(n, vector<int>(n, 0));
   vector<pair<int, int>> K(n);

   for (int i = 0; i < n; i++)
      {
         int x = 0, y = 0;
         cin >> x >> y;
         A[x - 1][y - 1] = 1;
         K[i] = {x - 1, y - 1};
      }
   
   vector<int>B(n);
   for (int j = 0; j < n; j ++)
      B[j] = minB(A, K, j);
   
   if (!B.empty()) 
   {
    cout << *min_element(B.begin(), B.end());
   } 

   return 0;
}
#include <iostream>
#include <vector>

using namespace std;

pair<pair<int, int>, pair<int, int>> findTwoMax(const vector<vector<int>>& matrix, int exclude_row, int exclude_col) 
{
   pair<int, int> max1 = {(exclude_row + 1) % matrix.size(), 0}; 
   pair<int, int> max2 = {(exclude_row + 1) % matrix.size(), 0}; 

   for (size_t i = 0; i < matrix.size(); ++i) {
      if (i == exclude_row) continue;
      for (size_t j = 0; j < matrix[0].size(); ++j) 
      {
         if (j == exclude_col) continue;
         if (matrix[i][j] >= matrix[max1.first][max1.second]) 
         {
            max2 = max1;
            max1 = {i, j};
         } 
         else if (matrix[i][j] >= matrix[max2.first][max2.second]) 
         {
            max2 = {i, j};
         }
      }
   }

   return {max1, max2};
}

pair<int, int> FindMax(const vector<vector<int>>& A, int i1, int j1, int i2, int j2) 
{
   int n = A.size();
   int m = A[0].size();
   pair<int, int> max = {i1, (j1 + 1) % m};

   
   for (int j = 0; j < m; ++j) 
   {
      if (j == j1 || j == j2) continue;
      if (A[i1][j] >= A[max.first][max.second]) 
      {
         max = {i1, j};
      }
      if (A[i2][j] >= A[max.first][max.second]) 
      {
         max = {i2, j};
      }
   }

   
   for (int i = 0; i < n; ++i) 
   {
      if (i == i1 || i == i2) continue;
      if (max.first == -1 || A[i][j1] >= A[max.first][max.second]) 
      {
            max = {i, j1};
      }
      if (max.first == -1 || A[i][j2] >= A[max.first][max.second]) 
      {
         max = {i, j2};
      }
   }

   return max;
}

int main ()
{
   int n = 0, m = 0;
   cin >> n >> m;
   vector<vector<int>> A(n, vector<int>(m, 0));

   for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
         cin >> A[i][j];

   auto [max1, max2] = findTwoMax(A, -1, -1);

   if (max1.first == max2.first)
   {
      auto [m1, m2] = findTwoMax(A, max1.first, -1);
      cout << max1.first + 1 << " " << m1.second + 1;
      return 0;
   }
   if (max1.second == max2.second)
   {
      auto [m1, m2] = findTwoMax(A, -1, max1.second);
      cout << m1.first + 1 << " " << max1.second + 1;
      return 0;
   }

   auto max12 = FindMax(A, max1.first, max1.second, max2.first, max2.second);

   if (max12.first == max2.first || max12.second == max1.second)
   {
      cout << max2.first + 1 << " " << max1.second + 1;
   }
   else
   {
      cout << max1.first + 1 << " " << max2.second + 1;
   }

   return 0;
}
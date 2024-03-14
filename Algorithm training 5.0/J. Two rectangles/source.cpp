#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int rr(vector<vector<int>> &A)
{
   int n = A.size();
   int m = A[0].size();
   int t = 2;
   int ans = 0;

   for (int i = 0; i < n; i++) 
   {
      for (int j = 0; j < m; j++) 
      {
         if (A[i][j] == 1) 
         {
               int left = j, a = 0;

               for (; left < m; left++) 
               {
                  if (A[i][left] != 1) break;
                  a++;
                  A[i][left] = t;
               }

               bool flag = true;

               if (j > 0 && i < n - 1)
               {
                  if (A[i+1][j-1] == 1)
                     flag = false;
                  if (i < n - 2)
                  {
                     if (A[i + 2][j] == 1)
                     {
                        flag = true;
                     }
                  }
                  if (j == m-1)
                     flag = true;
               }
               for (int k = i + 1; k < n && flag; k++) 
               {
                  left = j;
                  for (; left < j + a; left++) 
                  {
                     if (A[k][left] != 1) 
                     {
                           flag = false;
                           break;
                     }
                  }
                  if (flag) 
                  {
                     for (int l = j; l < j + a; l++) 
                     {
                        A[k][l] = t;
                     }
                  }
               }
               
               t++; 
               ans ++;
         }
      }
   }
   return ans;
}

int main()
{
   int n = 0, m = 0;
   cin >> n >> m;
   int sum = 0;
   vector<vector<int>>A(n, vector<int>(m, 0));

   for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
      {
         char c = '\0';
         cin >> c;
         if (c == '#') 
         {
            A[i][j] = 1;
            sum++;
         }
      }

   int ans = rr(A);
   
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         cout << A[i][j] << " ";
      }
      cout << endl;
   }


   if (ans > 2 || ans < 1 || sum == 1)
   {
      cout << "NO";
      return 0;
   }
   if (ans == 2)
   {
      cout << "YES" << endl;
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < m; j++)
         {
            if (A[i][j] == 0)cout << ".";
            if (A[i][j] == 2)cout << "a";
            if (A[i][j] == 3)cout << "b";
         }
         cout << endl;
      }
      return 0;
   }
   if (ans == 1)
   {
      cout << "YES" << endl;
      
      bool flag = true;
      int g = 0, d = 0;
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < m; j++)
         {
            if (A[i][j] == 2)
            {
               d = i;
               g++;
               break;
            }
         }
      }   

      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < m; j++)
         {
            if (A[i][j] == 0)cout << ".";
            if (A[i][j] == 2 && flag)
            {
               if (g == 1)
               {
                  cout << "a";
                  flag = false;
                  continue;
               }
               else
               {
                  if (i == d)
                  {
                     cout <<"a";
                     continue;
                  }
               }
            }
            if (A[i][j] == 2)cout << "b";
         }
         cout << endl;
      }
      return 0;
   }
   return 0;
}
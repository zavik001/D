#include <iostream>
#include <vector>

using namespace std;

int main ()
{
   int t = 0;
   cin >> t;

   vector<vector<int>> T(t);

   for (int i = 0; i < t; i++)
   {
      int n = 0;
      cin >> n;

      vector<int> A(n);
      for (int i = 0; i < n; i++)
      {
         cin >> A[i];
      }

      int min = A[0], len = 1;

      if (n == 1)
         T[i].push_back(1);
      else
         for (int left = 1; left < n; left++)
         {           
            if (min > len)
            {
               if (A[left] < min)
               {
                  if (A[left] > len)
                  {
                     len ++;
                     min = A[left];
                     if (left == n-1)
                     {
                        T[i].push_back(len);
                     }
                  }
                  else
                  {
                     T[i].push_back(len);
                     len = 1;
                     min = A[left];
                     if (left == n-1)
                     {
                        T[i].push_back(len);
                     }
                  }
               }
               else
               {
                  len++;
                  if (left == n-1)
                  {
                     T[i].push_back(len);
                  }
               }
            }
            else
            {
               T[i].push_back(len);
               len = 1;
               min = A[left];
               if (left == n-1)
               {
                  T[i].push_back(len);
               }
            }
         }
   }

   for (int i = 0; i < t; i ++)
   {
      cout << T[i].size() << endl;
      for (int j = 0; j < T[i].size(); j++)
         cout << T[i][j] << " ";
      cout << endl;
   }  

   return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

void find1(const pair<long long, long long>& A0) 
{
   cout << 3 << endl;
   cout << A0.first + 1 << " " << A0.second << endl;
   cout << A0.first + 1 << " " << A0.second + 1 << endl;
   cout << A0.first << " " << A0.second + 1 << endl;
}

void find2(const pair<long long, long long>& A0, const pair<long long, long long>& A1) 
{
   long long dx = A1.first - A0.first;
   long long dy = A1.second - A0.second;

   long long x3 = A0.first + dy;
   long long y3 = A0.second - dx;

   long long x2 = A1.first + dy;
   long long y2 = A1.second - dx;

   cout << 2 << endl;
   cout << x2 << " " << y2 << "\n";
   cout << x3 << " " << y3 << "\n";
}

bool isElementInVector(const vector<pair<long long, long long>>& A, const pair<long long, long long>& V4) 
{
   for (const auto& elem : A) 
   {
      if (elem.first == V4.first && elem.second == V4.second) 
      {
         return true; 
      }
   }
   return false; 
}

void square(vector<pair<long long, long long>>& A)
{
   int n = A.size();
   bool flag = false;
   pair<long long, long long> V4{10E14, 10E14};


   for (long long i = 0; i < n; i++)
   {
      long long x = A[i].first, y = A[i].second; 
      map <long long, vector<pair<long long, long long>>> M;

      for (int j = 0; j < n; j++)
      {
         if (i == j)continue;
         long long x1 = A[j].first, y1 = A[j].second;
         long long L = (x - x1) * (x - x1) + (y - y1) * (y - y1);
         M[L].push_back({x1, y1});
      }

      for (const auto &it : M)
      {
         long long L = it.first;
         vector<pair<long long, long long>> V = it.second;

         long long r = V.size();
         for (long long k = 0; k < r; k++)
         {
            long long x1 = V[k].first, y1 = V[k].second;
            for (long long f = k + 1; f < r; f ++)
            {
               long long x2 = V[f].first, y2 = V[f].second;
               long long L_x1y1_x2y2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

               if (L * 2 != L_x1y1_x2y2)
                  break;
               
               V4 = {x1 + x2 - x, y1 + y2 - y};
               
               if (isElementInVector(A, V4)) 
               {
                  flag = true;
                  break;
               } 
            }
            if(flag) break;
         }
         if(flag) break;
      }
      if(flag) break;
   }

   if (flag)
   {
      cout << 0;
      return;
   } 
   
   if (V4.first == 10E14)
   {
      find2(A[0], A[1]);
      return;
   }
   else
   {
      cout << 1 << endl;
      cout << V4.first << " " << V4.second;
      return;
   }
}

int main ()
{
   long long n = 0;
   cin >> n;
   vector<pair<long long, long long>> A(n);

   for (long long i = 0; i < n; i++)
      cin >> A[i].first >> A[i].second;

   if (n == 1)
   {
      find1(A[0]);
      return 0;
   }

   if (n == 2) 
   {
      find2(A[0], A[1]);
      return 0;
   }

   square(A);

   return 0;
}

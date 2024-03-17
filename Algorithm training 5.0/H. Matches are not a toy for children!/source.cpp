#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct elem
{
   int x1, y1, x2, y2;
};

int PER(vector<elem>& A, vector<elem>& B)
{
   int n = A.size();
   map<pair<int, int>, int> M;

   int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         x1 = B[i].x1 - A[j].x1;
         x2 = B[i].x2 - A[j].x2;
         y1 = B[i].y1 - A[j].y1;
         y2 = B[i].y2 - A[j].y2;
         if (x1 == x2 && y1 == y2)
            M[{x1,y1}]++;

         x1 = B[i].x1 - A[j].x2;
         x2 = B[i].x2 - A[j].x1;
         y1 = B[i].y1 - A[j].y2;
         y2 = B[i].y2 - A[j].y1;
         if (x1 == x2 && y1 == y2)
            M[{x1,y1}]++;
      }
   }

   auto maxElement = max_element(M.begin(), M.end(),
                                          [](const auto &a, const auto &b) 
                                          {
                                             return a.second < b.second;
                                          });;
   
   if (maxElement != M.end()) 
      return maxElement->second;
   else 
      return 0;
}

int main()
{
   int n = 0;
   cin >> n;

   vector<elem> A(n), B(n);

   for (int i = 0; i < n; i++)
      cin >> A[i].x1 >> A[i].y1 >> A[i].x2 >> A[i].y2;
   
   for (int i = 0; i < n; i++)
      cin >> B[i].x1 >> B[i].y1 >> B[i].x2 >> B[i].y2;
   
   int t = PER(A, B);

   cout << n - t;

   return 0;
}
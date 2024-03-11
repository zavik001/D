#include <iostream>
#include <vector>

using namespace std;


int maxP(int N, int K, vector<int> &A)
{
   int maxP = 0;

   for (int i = 0; i < N; i++)
   {
      for (int j = i + 1; j < min(N, K + i + 1); j++)
      {
         int x = A[j] - A[i];
         if (x > maxP)
            maxP = x;
      }
   }

   return maxP;
}

int main ()
{
   int N = 0, K = 0;
   cin >> N >> K;
   
   vector<int> A(N);

   for (int i = 0; i < N; i++)
   {
      cin >> A[i];
   }
   

   cout << maxP(N, K, A);

   return 0;
}
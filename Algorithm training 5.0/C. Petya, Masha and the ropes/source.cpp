#include <iostream>
#include <vector>

using namespace std;

int main ()
{
   int N = 0;
   cin >> N;
   vector<int> A(N);
   for (int i = 0; i < N; i++)
      cin >> A[i];

   int max = A[0];
   long long Sum = A[0];

   for (int i = 1; i < N; i++)
   {
      if (max < A[i])max = A[i];

      Sum += A[i];
   }
   Sum -= max;

   if (max > Sum) cout << max - Sum;
   else cout << Sum + max;

   return 0;
}


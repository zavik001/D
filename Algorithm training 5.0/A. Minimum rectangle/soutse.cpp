#include <iostream>
#include <vector>

using namespace std;

int main ()
{
   int K = 0;
   cin >> K;

   if (K == 0)
   {
      cout << 0;
      return 0;
   }

   vector <long long> X(K), Y(K);
   long long minx, miny, maxx, maxy;

   for (int i = 0; i < K; i++)
   {
      cin >> X[i] >> Y[i];
   }

   maxx = X[0];
   minx = X[0];
   maxy = Y[0];
   miny = Y[0];
   for (int i = 1; i < K; i++)
   {
      if (maxx < X[i])maxx = X[i];
      if (minx > X[i])minx = X[i];
      if (maxy < Y[i])maxy = Y[i];
      if (miny > Y[i])miny = Y[i];
   }

   cout << minx << " " << miny << " " << maxx << " " << maxy;

   return 0;
}
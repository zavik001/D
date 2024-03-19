#include <iostream>
#include <vector>

using namespace std;

int main ()
{
   int t = 0;
   cin >> t;
   vector<long long> A(t);

   for (int i = 0; i < t; i++)
   {
      int a = 0, b = 0, c = 0;
      long long m = 0;
      cin >> a >> b >> c;

      m += a;
      m += b / 3;
      b %= 3;
      if (b == 1)
      {
         if (c < 2)
            A[i] = -1;
         else 
         {
            c += b;
            m += c % 3 == 0 ? c / 3 : c / 3 + 1;
            A[i] = m;
         }
      }
      else if (b == 2)
      {
         if (c < 1)
            A[i] = -1;
         else 
         {
            c += b;
            m += c % 3 == 0 ? c / 3 : c / 3 + 1;
            A[i] = m;
         }
      }
      else
      {
         m += c % 3 == 0 ? c / 3 : c / 3 + 1;
         A[i] = m;
      }
   }

   for (int i = 0; i < t; i++)
      cout << A[i] << endl;

   return 0;
}
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
   int n = 0, s = 0, g = 0;
   cin >> n;
   int *a = new int[n];

   for (int i = 0; i < n; i++)
   {
      cin >> a[i];
      s += a[i];
   }

   for (int i = 0; i < n; i++)
   {
      cout << i * a[i] - g + s - g - a[i] * (n - i) << " ";
      g += a[i];
   }

   return 0;
}
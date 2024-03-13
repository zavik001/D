#include <iostream>

using namespace std;

int gcd(int a, int b) 
{
   if (b == 0) 
      return a;

   return gcd(b, a % b);
}

int main()
{
   int a = 0, b = 0, c = 0, d = 0;
   cin >> a >> b >> c >> d;

   int x = a * d + b * c, y = b * d;

   int NOD = gcd(x, y);

   x /= NOD;
   y /= NOD;

   cout << x << " " << y;

   return 0;
}
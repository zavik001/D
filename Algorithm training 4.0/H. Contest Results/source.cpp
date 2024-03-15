#include <iostream>

using namespace std;

int main()
{
   int a = 0, b = 0, n = 0;
   cin >> a >> b >> n;
   if (a > (b + n - 1) / n)
      cout << "YES";
   else 
      cout << "NO";

   return 0;
}
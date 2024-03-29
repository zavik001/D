#include <iostream>
#include <cmath>
#include <string>

using namespace std;


bool isBinaryDecimal(int num) 
{
   string numStr = to_string(num);
   for (char digit : numStr) 
      if (digit != '0' && digit != '1') 
         return false;
   return true;
}

bool canBeBinaryProduct(int n) 
{
   if (isBinaryDecimal(n)) return true;
   for (int i = 2; i <= sqrt(n); ++i) 
   {
      if (n % i == 0) 
      {
         if (isBinaryDecimal(i) && canBeBinaryProduct(n / i)) 
            return true;
      }
   }
   return false;
}

int main() 
{
   int t;
   cin >> t; 

   for (int i = 0; i < t; ++i) 
   {
      int n;
      cin >> n; 
      if (canBeBinaryProduct(n)) 
         cout << "YES" << endl;
      else 
         cout << "NO" << endl;
   }

   return 0;
}

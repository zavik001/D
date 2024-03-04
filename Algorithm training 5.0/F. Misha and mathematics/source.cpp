#include <iostream>

using namespace std;

int main ()
{
   int n = 0, a = 0;
   bool flag = false;
   cin >> n;
   cin >> a;
   if (a % 2 == 0)
      flag = false;
   else
      flag = true;
   a = 0;

   for (int i = 1; i < n; i++)
   {
      cin >> a;
      if (a % 2 == 0)
      {
         if (flag)
            cout << "+";
         else 
         {
            cout << "+";
            flag = false;
         }
      }
      else 
      {
         if (flag)
         {
            cout << "x";
         }
         else 
         {
            cout << "+";
            flag = true;
         }
      } 
      a = 0;     
   }

   return 0;
}


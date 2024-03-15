#include <iostream>
#include <vector>

using namespace std;

string generateString(int n) 
{
   if (n == 1) 
   {
      return "";
   } 
   else if (n == 2) 
   {
      return "AA";
   } 
   else 
   {
      string result = "";
      if (n % 2 == 0)
      {
         for (int i = 0; i < n/2; i++)
         {
            if (i % 2 == 0)
               result += "AA";
            else
               result += "BB";
         }
      }
      else
      {
         return "";
      }
      return result;
   }
}

int main ()
{
   int t = 0;
   cin >> t;
   vector <string> T(t);

   for (int i = 0; i < t; i++)
   {
      int n = 0;
      cin >> n;
      T[i] = generateString(n);
   }

   for (int i = 0; i < t; i++)
   {
      if (T[i].empty())
         cout << "NO"<< endl;
      else
      {
         cout << "YES" << endl;;
         cout << T[i] << endl;
      }
   }

   return 0;
}
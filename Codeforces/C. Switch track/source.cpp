#include <iostream>
#include <vector>

using namespace std;

bool fuc(int n, string s1, string s2)
{
   if (n == 2)
   {
      return true;
   }

   int x = 0, y = 0;
   for (int i = 0; i < n; i++)
   {
      if (x == 0)
      {
         if (s1[y+1] == '>')
         {
            y = y + 1;
         }
         else
         {
            x = 1;
         }
      }
      else
      {
         if (s2[y+1] == '>')
         {
            y = y + 1;
         }
         else
         {
            x = 0;
         }
      }
   }
   if (x == 1 && y == n - 1)
      return true;
   else  
      return false;
}

int main ()
{
   int t = 0;
   cin >> t;
   vector <int> T(t);

   for (int i = 0; i < t; i++)
   {
      int n = 0;
      cin >> n;

      string s1, s2;
      cin >> s1 >> s2;
      
      bool f = fuc(n, s1, s2);
      if (f)
         T[i] = 1;
      else 
         T[i] = 0;
   }

   for (int i = 0; i < t; i++)
   {
      if (T[i] == 0)
         cout << "NO"<< endl;
      else
      {
         cout << "YES" << endl;;
      }
   }

   return 0;
}
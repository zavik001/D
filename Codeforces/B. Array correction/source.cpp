#include <iostream>
#include <vector>
 
using namespace std;
 
 
bool add(vector<int> &A, int x)
{
   bool flag = false;
   if (A.empty())
   {
      if (x > 9)
      {
         int digit1 = x / 10;
         int digit2 = x % 10;
         if (digit2 < digit1)
         {
            A.push_back(x);
         }
         else
         {
            A.push_back(digit1);
            A.push_back(digit2);
         }
      }
      else
      {
         A.push_back(x);
      }
      return true;
   }
 
   int q = A.back();
 
   if (x > 9)
   {
      int digit1 = x / 10;
      int digit2 = x % 10;
 
      if (digit2 < digit1)
      {
         if (x < q)
            return false;
         else 
         {
            A.push_back(x);
            return true;
         }
      }
      else
      {
         if (digit1 >= q)
         {
            A.push_back(digit1);
            A.push_back(digit2);
            return true;
         }
         else
         {
            if (x < q)
               return false;
            else 
            {
               A.push_back(x);
               return true;
            }
         }
      }
   }
   else
   {
      if (x < q)
         return false;
      else 
      {
         A.push_back(x);
         return true;
      }
   }
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
      bool flag = false;
      vector <int>A(n), B;
      for (int i = 0; i < n; i++)
      {
         cin >> A[i];
      }
      
      for (int i = 0; i < n; i++)
      {
         flag = add(B, A[i]);
         if (!flag) break;
      }
 
      if (flag)
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
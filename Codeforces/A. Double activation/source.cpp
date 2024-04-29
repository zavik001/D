#include <bits/stdc++.h>
using namespace std;

int main ()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 0; 
   cin >> t;
   while(t--)
   {
      int n = 0;
      cin >> n;
      
      string s;
      cin >> s;

      int kol = 0;
      for (int i = 0; i < n; i++)
         if (s[i] == '1')
            kol++;
      
      if (kol == 2)
      {
         bool flag = false;
         for (int i = 1; i < n; i++)
            if(s[i - 1] == '1' && s[i] == '1')
               flag = true;
         
         if(flag) 
            cout << "NO" << '\n';
         else  
            cout << "YES" << '\n';
         continue;
      }

      if (kol & 1)
         cout << "NO" << '\n';
      else
         cout << "YES" << '\n';
   }
   

   return 0;
}

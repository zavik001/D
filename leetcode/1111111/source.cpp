#include <bits/stdc++.h>
using namespace std;

int main() 
{
   ios::sync_with_stdio(0);
   cin.tie(nullptr);
   
   string str;
   getline(cin >> str;

   for (int i = 0; i < 256; i++) 
   {
      char ch = static_cast<char>(i);
      int count = 0;
      
      for (char c : str) 
         if (c == ch) 
            count++;

      if (count == 1)
         cout << ch << " ";

      count = 0;
   }

   return 0;
}

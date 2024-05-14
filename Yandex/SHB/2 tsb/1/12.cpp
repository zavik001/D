#include<bits/stdc++.h>
using namespace std;

bool checkWin(map<int, map<int, int>>& m, int x, int y, int k) 
{
   auto checkDirection = [&](int dx, int dy) 
   {
      int c = 1;
      for (int i = 1; i <= 4; i++) 
      {
         if (m[x + i * dx][y + i * dy] == k) 
            c++;
         else 
            break;
      }
      return c;
   };

   for (int dx = -1; dx <= 1; dx++) 
   {
      for (int dy = -1; dy <= 1; dy++) 
      {
         if (dx == 0 && dy == 0) continue; 
         int count = checkDirection(dx, dy) + checkDirection(-dx, -dy) - 1; 
         if (count >= 5) return true; 
      }
   }

   return false; 
}

int main() 
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   
   int n = 0, x = 0, y = 0, con = 0;
   bool flag = true;
   cin >> n;

   map<int, map<int, int>> A;
   for (int i = 0; i < n; i++) 
   {
      cin >> x >> y;
      if (i & 1) 
      {
         con = 2;
         A[x][y] = con;
      }
      else 
      {
         con = 1;
         A[x][y] = con;
      }

      if (checkWin(A, x, y,con) && flag) 
      {
         flag = false;
         if (i < n - 1) 
         {
            cout << "Inattention"<<endl;
            continue;
         }
         if (i & 1) 
         {
            cout << "Second"<<endl;
            continue;
         }
         else 
         {
            cout << "First"<<endl;
            continue;
         }
      }
   }
   if (flag) 
      cout << "Draw";

   return 0;
}
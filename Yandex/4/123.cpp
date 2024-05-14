#include<bits/stdc++.h>
using namespace std;

bool chech(int status, int bias,int index, map<int,int> &M, vector<int> &Way, string &h)
{
   if (h[index] == 'L' || h[index] == 'R')
      bias += Way[index];

   if (h[index] == 'F') 
   {
      bias += status * Way[index];
      index += Way[index];

      if (index < h.size())
         bias += Way[index];
   }
   M[bias]++;
   return false;
}

int main()
{
   int n;
   string h;
   cin >> n >> h;

   vector<int> Way(n);
   int bias = 0;
   int c = 0;

   for (int i = n - 1; i >= 0; i--) 
   {
      if (h[i] == 'R') 
      {
         bias = c + bias;
         Way[i] = bias;
         c = 0;
      }

      if (h[i] == 'L') 
      {
         bias =  bias - c;
         Way[i] = bias;
         c = 0;
      }

      if (h[i] == 'F') 
      {
         c++;
         Way[i] = c;
      }
   }

   map<int,int> M;
   int status = 1;
   bias = 0;

   for (int i = 0; i <= n - 1; i++) 
   {  
      if (h[i] == 'R') 
      {
         chech(-1, bias, i + 1, M, Way, h);
         chech(status, bias + 1 * status, i + 1, M, Way, h);
         status = 1;
      }

      if (h[i] == 'L') 
      {
         chech(1, bias,i + 1, M, Way, h);
         chech(status, bias + 1 * status, i + 1, M, Way, h);
         status = -1;
      }

      if (h[i] == 'F') 
      {
         chech(1, bias, i + 1, M, Way, h);
         chech(-1, bias, i + 1, M, Way, h);
         bias += status;
      }
   }

   cout << M.size();

   return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>& a) 
{
   for (int i = 0; i < a.size(); i++) 
      cout << a[i];
   
   cout << endl;
}

void create(vector<int> &a, int n)
{
   if (a.size() == n)
   {
      print(a);
      return;
   }

   for (int i = 1; i <= n; i++)
      if (find(a.begin(), a.end(), i) == a.end())
      {
         a.push_back(i);
         create(a, n);
         a.pop_back();
      }
}

int main() 
{
   int N;
   cin >> N;

   vector<int> a;

   create(a, N);


   return 0;
}

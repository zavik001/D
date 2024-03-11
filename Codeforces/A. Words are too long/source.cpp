#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
   int n = 0;
   cin >> n;
   vector <string> A(n);

   for (int i = 0; i < n; i++)
   {
      string s;
      cin >> s;

      if (s.size() > 10)
      {
         string s2;
         int t = s.size();
         s2 = s[0] + to_string(t - 2) + s[t - 1];
         A[i] = s2;
      }
      else
         A[i] = s;
   }

   for (int i = 0; i < A.size(); i++)
      cout << A[i] << endl;

   return 0;
}
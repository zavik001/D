#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long Polindrome(string s)
{
   int n = s.size();
   vector<int> ro(n), re(n);
   for (int i = 0, l = 0, r = -1; i < n; ++i) {
      int k = (i > r) ? 1 : min(ro[l + r - i], r - i + 1);
      for (; 0 <= i - k && i + k < n && s[i - k] == s[i + k]; ++k);
      ro[i] = --k;
      if (i + k > r) {
         l = i - k;
         r = i + k;
      }
   }
   for (int i = 0, l = 0, r = -1; i < n; ++i) {
      int k = (i > r) ? 0 : min(re[l + r - i + 1], r - i + 1);
      for (; 0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]; ++k);
      re[i] = k--;
      if (i + k > r) {
         l = i - k - 1;
         r = i + k;
      }
   }

   long long sum = 0;
   for (int i = 0; i < n; i++)
      sum += re[i] + ro[i];

   return sum;
}

int main()
{
   string s;
   cin >> s;

   cout <<  Polindrome(s) + s.size();

   return 0;
}

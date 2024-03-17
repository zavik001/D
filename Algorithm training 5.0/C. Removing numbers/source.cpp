#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() 
{

   int n;
   cin >> n;
   if (n == 1)
   {
      cout << 0;
      return 0;
   }

   vector<int> a(n);
   map<int, int> freq;

   for (int i = 0; i < n; ++i) 
   {
      cin >> a[i];
      freq[a[i]]++;
   }

   int max_count = 0;
   for (auto& pair : freq) 
   {
      max_count = max(max_count, pair.second);
   }

   auto it = freq.begin(), iq = freq.begin();
   ++it;

   for ( ; it != freq.end(); ++it)
   {
      if (abs(it->first - iq->first) == 1)
      {
         max_count = max(max_count, it->second + iq->second);
      }
      iq = it;
   }

   
   cout << n - max_count << endl;

   for (const auto& pair : freq) {
      cout << "Element: " << pair.first << ", Frequency: " << pair.second << endl;
   }

   return 0;
}

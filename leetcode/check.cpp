#include <iostream>
#include <algorithm>
using namespace std;

void solution(string &s)
{
   size_t n = s.size();

   for (int i = 0; i < n; )
   {
      if (s[i] == ' ')
         i++;
      else
      {
         int start = i, end = i;

         for ( ; end < n && s[end] != ' '; end++);
         i = end + 1;

         reverse(s.begin() + start, s.begin() + end);
      }
   }
}

int main ()
{
   string s;
   getline(cin, s);

   solution(s);

   cout << s;

   return 0;
}
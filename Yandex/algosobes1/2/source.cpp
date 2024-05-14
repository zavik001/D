#include <bits/stdc++.h>
using namespace std;

void RemoveSpaces(string &s)
{
   string temp;
   stringstream ss(s);
   while (ss >> s)
      temp += s + ' ';
   s = temp.substr(0, temp.length() - 1); 
}

int main()
{
   string s;
   getline(cin , s);

   RemoveSpaces(s);

   cout << s << "\n";
   cout << s.size();

   return 0;
}

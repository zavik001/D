#include <bits/stdc++.h>
using namespace std;

bool check(const string& s) 
{
   regex digit_regex("(.*[0-9].*)");
   bool has_digit = regex_match(s, digit_regex);
   bool has_upper = any_of(s.begin(), s.end(), ::isupper);
   bool has_lower = any_of(s.begin(), s.end(), ::islower);
   
   return has_digit && has_upper && has_lower && s.size() > 7;
}

int main()
{
   string s;
   cin >> s;
   
   check(s) ? cout << "YES" : cout << "NO"; 

   return 0;
}

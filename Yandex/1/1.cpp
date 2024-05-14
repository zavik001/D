#include <bits/stdc++.h>
using namespace std;

int main() 
{
   string input;
   getline(cin, input);
   
   istringstream stream(input);
   vector<string> elements;
   string element = "";
   
   for (char ch : input) 
   {
      if (ch == ' ' || ch == ',') 
      {
         if (!element.empty()) 
         {
            elements.push_back(element);
            element = "";
         }
         if (ch == ',') 
            elements.push_back(",");
      }
      else 
         element += ch;
   }
   
   if (!element.empty()) 
      elements.push_back(element);
   
   int maxLen = 0;
   for (const string& el : elements) 
      if (el.length() > maxLen) 
         maxLen = el.length();

   maxLen *= 3;
   int len = 0;
   for (int i = 0; i < elements.size(); i++)
   {
      if (elements[i] == ",") 
         continue;

      string el = elements[i];
      if (i < elements.size() - 1)
         if (elements[i + 1] == ",")
            el += elements[i + 1];
      
      if (len + el.length() < maxLen)
      {
         if (len != 0)
         {
            cout << " ";
            len ++;
         }
         cout << el;
         len += el.length();
      }
      else
      {
         cout << endl;
         cout << el;
         len = el.length();
      }
   }
   
   return 0;
}
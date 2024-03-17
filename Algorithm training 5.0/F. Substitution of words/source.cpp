#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int main() 
{
   string line1, line2;

   getline(cin, line1);

   getline(cin, line2);

   vector<string> words;
   map<string, string> A;

   stringstream ss1(line1);
   stringstream ss2(line2);
   string word;

   for ( ; ss1 >> word; ) 
   {
      A[word] = word;
   }

   
   for ( ;ss2 >> word;)
   {
      string s;
      bool flag = false;
      for (int i = 0; i < word.size();  i++)
      {
         s += word[i];
         if (A.find(s) != A.end()) 
         {
            flag = true;
            break;
         }
      }
      if (flag)
      {
         cout << s << " ";
      }
      else 
         cout << word << " ";
   }
   
   //cout << endl;
   //for (const auto& pair : A) {
   //   cout << "Element: " << pair.first << ", Frequency: " << pair.second << endl;
   //}


   return 0;
}

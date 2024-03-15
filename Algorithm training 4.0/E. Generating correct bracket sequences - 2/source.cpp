#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

string KK = "([";
string h2 = "([)";
string h3 = "([]";


int rec(int k, int l, string a, int n) {
   if (a.size() == n) {
      cout << a << endl;
      return 0;
   }
   int j = 3 - (k == 0);
   for (int i = 0; i < j; i++) {
      if (k == 0) {

         rec(k + 1, l - 1, a + KK[i], n);

      }
      else {
         stack <char> st;
         char kal = a[0];
         for (int i = 0; i < a.size(); i++) {

            if (a[i] == '(' or a[i] == '[') {
               st.push(a[i]);
            }
            else {
               st.pop();
            }
         }
         if (st.size() > 0) {
            kal = st.top();
         }
         if (k < l) {
            int ii = 1;
            if (i == 2) {
               ii = -1;
            }
            if (kal == '(') {

               rec(k + ii, l - 1, a + h2[i], n);
            }
            else {
               rec(k + ii, l - 1, a + h3[i], n);
            }
         }
         else {

            if (kal == '(') {
               rec(k - 1, l - 1, a + ')', n);
            }
            else {
               rec(k - 1, l - 1, a + ']', n);
            }
            break;


         }
      }



   }
   return 0;
}



int main() {
   int n;
   cin >> n;
   if (n % 2 == 1) {
      return 0;
   }
   vector<vector<int>> s;
   int k = 1;
   bool* t = new bool[n + 1] {};
   string a;
   rec(0, n, a, n);

   return 0;
}
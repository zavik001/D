#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int mi = -1;
int graf(int v, int** a, int n, int w, bool* t, int vk) {
   if (v == 0 and vk == n) {
      if (w < mi or mi == -1) {
         mi = w;
      }
      return 0;
   }
   if (v == -1) {
      v = 0;
   }

   for (int i = 0; i < n; i++) {

      if (a[v][i] != 0 and t[i] != true) {
         t[i] = true;
         graf(i, a, n, w + a[v][i], t, vk + 1);
         t[i] = false;
      }
   }
   return 0;
}

int main() {
   int n;
   cin >> n;
   if (n == 1) {
      cout << 0;
      return 0;
   }
   int** a = new int* [n];
   for (int i = 0; i < n; i++) {
      a[i] = new int[n];
      for (int j = 0; j < n; j++) {
         cin >> a[i][j];
      }
   }
   bool* t = new bool[n];
   graf(-1, a, n, 0, t, 0);
   cout << mi;
   return 0;
}